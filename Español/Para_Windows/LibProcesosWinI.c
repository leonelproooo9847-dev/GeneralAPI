// LibProcesosWinI.c
#include <windows.h>
#include "LibProcesosWin.h"

Byte_t CerrarManejador(
    MANEJADOR MANEJADOR_A_CERRAR
) {
    if (MANEJADOR_A_CERRAR == NULL || MANEJADOR_A_CERRAR == INVALID_HANDLE_VALUE)
        return CerrarManejador_Error_Manejador_Invalido;

    WINBOOL exito = CloseHandle(MANEJADOR_A_CERRAR);
    if (exito == FALSE)
        return CerrarManejador_Error_CloseHandle;
    
    return 0;
}

/*****************************************************************************************/
/*****************************************************************************************/

Byte_t CrearProceso(
    PARAMETROS_DEL_PROCESO*  PARAMETROS_ENTRADA,
    INFORMACION_DEL_PROCESO* INFORMACION_SALIDA
) {
    #define dParams         (*PARAMETROS_ENTRADA)
    #define dInformacion    (*INFORMACION_SALIDA)
    if (PARAMETROS_ENTRADA == NULL)
        return CrearProceso_Error_Estructura_Parametros_NULL;
    if (INFORMACION_SALIDA == NULL)
        return CrearProceso_Error_Estructura_Informacion_NULL;

    char* dir_ejecutable    = NULL;
    char* linea_de_comandos = NULL;
    char* nombre_de_ventana = NULL;
    DWORD pos_y, pos_x, tam_y, tam_x;
        pos_y = 0;
        pos_x = 0;
        tam_y = 0;
        tam_x = 0;
    Bool_t pos_tam_predeterminado = No;
    Bool_t herencia_de_consola = No;
    Bool_t crear_ventana = No;
    Bool_t nombrar_ventana = No;

    if (dParams._DIRECCION_DEL_EJECUTABLE_ == NULL)
        return CrearProceso_Error_Direccion_NULL;
    else
        dir_ejecutable = dParams._DIRECCION_DEL_EJECUTABLE_;
    
    if (dParams._LINEA_DE_COMANDOS_ != NULL)
        linea_de_comandos = dParams._LINEA_DE_COMANDOS_;
    
    if (dParams.ACTIVAR_CONFIGURACION == Si) {
        
        if (dParams.Campo_configuracion.CREAR_VENTANA == Si) {
            crear_ventana = Si;
            if (dParams.Campo_configuracion.Campo_dimenciones_de_ventana.PREDETERMINADOS == Si) {
                pos_tam_predeterminado = Si;
            } else {
                pos_x = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._POS_EJE_X_);
                pos_y = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._POS_EJE_Y_);
                tam_x = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._TAM_EJE_X_);
                tam_y = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._TAM_EJE_Y_);
            }

            if (dParams.Campo_configuracion.NOMBRAR_VENTANA == Si) {
                if (dParams.Campo_configuracion._NOMBRE_DE_LA_VENTANA_ != NULL) {
                    nombre_de_ventana = dParams.Campo_configuracion._NOMBRE_DE_LA_VENTANA_;
                    nombrar_ventana = Si;
                }
                else
                    nombrar_ventana = No;
            } else
                nombrar_ventana = No;
            
        } else {
            if (dParams.Campo_configuracion.PERMITIR_HERENCIA_DE_CONSOLA == Si) {
                herencia_de_consola = Si;
            }
        }
    }

    WINBOOL Heredar = FALSE;
    DWORD flags = 0;
    STARTUPINFOA informacion_1 = {0};
    PROCESS_INFORMATION info_proceso = {0};
    informacion_1.cb = sizeof(STARTUPINFOA);


    SECURITY_ATTRIBUTES atributos = {0};
    atributos.nLength = sizeof(SECURITY_ATTRIBUTES);
    atributos.bInheritHandle = TRUE;
    HANDLE NoHeredar = CreateFileA(
        "NUL",
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        &atributos,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (NoHeredar == NULL || NoHeredar == INVALID_HANDLE_VALUE)
        return CrearProceso_Error_CreateFileA_MANEJADOR_Invalido;

    if (crear_ventana) {
        informacion_1.dwFlags |= CREATE_NEW_CONSOLE;
        if (nombrar_ventana == Si) {
            informacion_1.dwFlags |= STARTF_TITLEISLINKNAME;
            informacion_1.lpTitle = nombre_de_ventana;
        }
        
        if (pos_tam_predeterminado == No) {
            informacion_1.dwFlags |= STARTF_USEPOSITION | STARTF_USESIZE;
            informacion_1.dwX = pos_x;
            informacion_1.dwY = pos_y;
            informacion_1.dwXSize = tam_x;
            informacion_1.dwYSize = tam_y;
        }
        Heredar = FALSE;
        flags |= CREATE_NEW_CONSOLE;
    } else if (
        herencia_de_consola 
        &&
        (
            dParams.Campo_configuracion.Campo_herencias.HEREDAR_FLUJO_ERROR  == Si ||
            dParams.Campo_configuracion.Campo_herencias.HEREDAR_FLUJO_INPUT  == Si ||
            dParams.Campo_configuracion.Campo_herencias.HEREDAR_FLUJO_OUTPUT == Si
        )
    ) {
        informacion_1.dwFlags |= STARTF_USESTDHANDLES;
        // TODO: revisar si es necesario que se pueda forzar la herencia de los flujos de la consola.
        // TODO: implementar el forzado de la herencia de los flujos de la consola.
        
        if (dParams.Campo_configuracion.Campo_herencias.HEREDAR_FLUJO_ERROR == Si) {
            HANDLE hError = GetStdHandle(STD_ERROR_HANDLE);
            if (hError == NULL || hError == INVALID_HANDLE_VALUE) {
                CloseHandle(NoHeredar);
                return CrearProceso_Error_GetStdHandle_Configurar_Herencia_stdErr;
            }
            
            informacion_1.hStdError = hError;
        } else {
            informacion_1.hStdError = NoHeredar;
        }

        if (dParams.Campo_configuracion.Campo_herencias.HEREDAR_FLUJO_INPUT == Si) {
            HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
            if (hInput == NULL || hInput == INVALID_HANDLE_VALUE) {
                CloseHandle(NoHeredar);
                return CrearProceso_Error_GetStdHandle_Configurar_Herencia_stdIn;
            }
            
            informacion_1.hStdInput = hInput;
        } else {
            informacion_1.hStdInput = NoHeredar;
        }

        if (dParams.Campo_configuracion.Campo_herencias.HEREDAR_FLUJO_OUTPUT == Si) {
            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOutput == NULL || hOutput == INVALID_HANDLE_VALUE) {
                CloseHandle(NoHeredar);
                return CrearProceso_Error_GetStdHandle_Configurar_Herencia_stdOut;
            }
            
            informacion_1.hStdOutput = hOutput;
        } else {
            informacion_1.hStdOutput = NoHeredar;
        }
        Heredar = TRUE;
    } else {
        informacion_1.dwFlags |= STARTF_USESTDHANDLES;
        informacion_1.hStdError = NoHeredar;
        informacion_1.hStdInput = NoHeredar;
        informacion_1.hStdOutput = NoHeredar;
        Heredar = TRUE;
    }


    WINBOOL exito = CreateProcessA(
        dir_ejecutable,
        linea_de_comandos,
        NULL,
        NULL,
        Heredar,
        flags,
        NULL,
        NULL,
        &informacion_1,
        &info_proceso
    );

    CloseHandle(NoHeredar);

    if (exito == FALSE) {
        dInformacion.PROCESO_ID = 0;
        dInformacion.HILO_ID = 0;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO = NULL;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO = NULL;
        return CrearProceso_Error_CreateProcessA;
    } else {
        dInformacion.PROCESO_ID = info_proceso.dwProcessId; 
        dInformacion.HILO_ID    = info_proceso.dwThreadId;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO = info_proceso.hProcess;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO    = info_proceso.hThread;
        return 0;
    }

    #undef dParams
    #undef dInformacion
}

/*****************************************************************************************/
/*****************************************************************************************/

Byte_t CerrarHiloYProceso(
    INFORMACION_DEL_PROCESO* INFORMACION_DEL_PROCESO
) {
    #define dInformacion    (*INFORMACION_DEL_PROCESO)
    if (INFORMACION_DEL_PROCESO == NULL)
        return CerrarProceso_Error_Estructura_Informacion_NULL;

    WINBOOL error = 0;
    if (dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO != NULL && dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO != INVALID_HANDLE_VALUE) {
        error = CloseHandle(dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO);
        if (error != 1)
            return CerrarProceso_Error_CloseHandle_Hilo;
    }

    if (dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO != NULL && dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO != INVALID_HANDLE_VALUE) {
        error = CloseHandle(dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO);
        if (error != 1)
            return CerrarProceso_Error_CloseHandle_Proceso;
    }

    #undef dInformacion
    return 0;
}
