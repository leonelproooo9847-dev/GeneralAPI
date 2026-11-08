#include "Para_Windows/LibWin.h"

int main() {
    // Probemos mi librería de Windows

    Imprimir("No voy a decir 'Hola mundo'\n", NULL);
    
    Escribir("Error\n", 7, NULL, CONSOLA_ERROR);


    PARAMETROS_DEL_PROCESO params = {0};
    INFORMACION_DEL_PROCESO info = {0};

    params._DIRECCION_DEL_EJECUTABLE_ = "C:\\Users\\Usuario\\Desktop\\libreria_leo\\Prueba.exe";
    params.ACTIVAR_CONFIGURACION = Si;
    params.Campo_configuracion.CREAR_VENTANA = Si;
    params.Campo_configuracion.NOMBRAR_VENTANA = Si;
    params.Campo_configuracion._NOMBRE_DE_LA_VENTANA_ = "Mi ventana de prueba";
    params.Campo_configuracion.PERMITIR_HERENCIA_DE_CONSOLA = No;

    Byte_t error = 0;
    if (error = CrearProceso(
        &params,
        &info
    ) != 0) {
        Imprimir("Error al crear el proceso\n", NULL);
        Imprimir("Código de error: %x", &error);
        return 1;
    }

    error = CerrarHiloYProceso(&info);
    if (error != 0) {
        Imprimir("Error al cerrar el proceso\n", NULL);
        Imprimir("Código de error: %x", &error);
        return 1;
    }

    char buffer[50] = {0};
    ENTRADA_PARAMs entrada = {0};
    entrada._PUNTERO_BUFFER_DE_ENTRADA_ = buffer;
    entrada._LONGITUD_DEL_BUFFER_ = sizeof(buffer);
    entrada._PERMITIR_CONFIGURACION_ = No;
    Entrada(&entrada);

    return 0;
}

/* comando:
    gcc PruebaWin.c APIGenerali.c ./Para_Windows/LibProcesosWini.c ./Para_Windows/MensajeErrorWini.c ./Para_Windows/Entrada_y_Salida/GeneralI.c -o PruebaWin.exe
*/
