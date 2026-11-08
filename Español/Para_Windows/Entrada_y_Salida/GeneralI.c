// LibpWinImplem.c

//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
// incluciones

#include <windows.h>
#include "EntradaSalidaWin.h"

/*
CP_ACP	        0	    Página de códigos ANSI predeterminada de Windows.
CP_OEMCP	    1	    Página de códigos OEM predeterminada.
CP_MACCP	    2	    Página de códigos de Macintosh, para compatibilidad heredada.
CP_THREAD_ACP	3	    Página ANSI predeterminada asociada al subproceso actual.
CP_SYMBOL	    42	    Página de códigos de símbolos.
CP_UTF7	        65000	Codificación UTF-7, heredada y desaconsejada para usos nuevos.
CP_UTF8
*/

//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//
//
//
//
//
//
//
//
//
//
//
//
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII



void ImprimirTipoTecla(
    Byte_t TECLA_ESPECIAL_A_IMPRIMIR
) {
    switch (TECLA_ESPECIAL_A_IMPRIMIR)
    {
        case TECLA_CARACTER     :       Imprimir("CARACTER", NULL);       break; 
        case TECLA_CONTROL_DE   :       Imprimir("CONTROL_DE", NULL);     break;
        case TECLA_CONTROL_IZ   :       Imprimir("CONTROL_IZ", NULL);     break;
        case TECLA_CONTROL      :       Imprimir("CONTROL", NULL);        break;
        case TECLA_ALT_DE       :       Imprimir("ALT_DE", NULL);         break;
        case TECLA_ALT_IZ       :       Imprimir("ALT_IZ", NULL);         break;
        case TECLA_ALT          :       Imprimir("ALT", NULL);            break;
        case TECLA_OS_DE        :       Imprimir("OS_DE", NULL);          break;
        case TECLA_OS_IZ        :       Imprimir("OS_IZ", NULL);          break;
        case TECLA_OS           :       Imprimir("OS", NULL);             break;
        case TECLA_SHIFT_DE     :       Imprimir("SHIFT_DE", NULL);       break;
        case TECLA_SHIFT_IZ     :       Imprimir("SHIFT_IZ", NULL);       break;
        case TECLA_SHIFT        :       Imprimir("SHIFT", NULL);          break;
        case TECLA_ESCAPE       :       Imprimir("ESCAPE", NULL);         break;
        case TECLA_TAB          :       Imprimir("TAB", NULL);            break;
        case TECLA_BACKSPACE    :       Imprimir("BACKSPACE", NULL);      break;
        case TECLA_ENTER        :       Imprimir("ENTER", NULL);          break;
        case TECLA_SUPRIMIR     :       Imprimir("SUPRIMIR", NULL);       break;
        case TECLA_INSERTAR     :       Imprimir("INSERTAR", NULL);       break;
        case TECLA_FLECHA_ARRIBA:       Imprimir("FLECHA_ARRIBA", NULL);  break;
        case TECLA_FLECHA_ABAJO :       Imprimir("FLECHA_ABAJO", NULL);   break;
        case TECLA_FLECHA_IZ    :       Imprimir("FLECHA_IZ", NULL);      break;
        case TECLA_FLECHA_DE    :       Imprimir("FLECHA_DE", NULL);      break;
        case TECLA_INICIO       :       Imprimir("INICIO", NULL);         break;
        case TECLA_FIN          :       Imprimir("FIN", NULL);            break;
        case TECLA_PAG_ARRIBA   :       Imprimir("PAG_ARRIBA", NULL);     break;
        case TECLA_PAG_ABAJO    :       Imprimir("PAG_ABAJO", NULL);      break;
        case TECLA_F1       :   Imprimir("F1", NULL);     break;
        case TECLA_F2       :   Imprimir("F2", NULL);     break;
        case TECLA_F3       :   Imprimir("F3", NULL);     break;
        case TECLA_F4       :   Imprimir("F4", NULL);     break;
        case TECLA_F5       :   Imprimir("F5", NULL);     break;
        case TECLA_F6       :   Imprimir("F6", NULL);     break;
        case TECLA_F7       :   Imprimir("F7", NULL);     break;
        case TECLA_F8       :   Imprimir("F8", NULL);     break;
        case TECLA_F9       :   Imprimir("F9", NULL);     break;
        case TECLA_F10      :   Imprimir("F10", NULL);    break;
        case TECLA_F11      :   Imprimir("F11", NULL);    break;
        case TECLA_F12      :   Imprimir("F12", NULL);    break;
        case TECLA_F13      :   Imprimir("F13", NULL);    break;
        case TECLA_F14      :   Imprimir("F14", NULL);    break;
        case TECLA_F15      :   Imprimir("F15", NULL);    break;
        case TECLA_F16      :   Imprimir("F16", NULL);    break;
        case TECLA_F17      :   Imprimir("F17", NULL);    break;
        case TECLA_F18      :   Imprimir("F18", NULL);    break;
        case TECLA_F19      :   Imprimir("F19", NULL);    break;
        case TECLA_F20      :   Imprimir("F20", NULL);    break;
        case TECLA_F21      :   Imprimir("F21", NULL);    break;
        case TECLA_F22      :   Imprimir("F22", NULL);    break;
        case TECLA_F23      :   Imprimir("F23", NULL);    break;
        case TECLA_F24      :   Imprimir("F24", NULL);    break;
        default:
            Imprimir("TECLA_INDETERMINADA", NULL); break; 
    }
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t CapturarTeclaUTF8(
    EVENTO_TECLA* INFORMACION_DE_LA_TECLA
) {
    #define dtecla (*tecla)
    #define dinfo   (*INFORMACION_DE_LA_TECLA)

    if (INFORMACION_DE_LA_TECLA == NULL)
        return GENERAL_Error_Puntero_NULL;

    dinfo.CARACTER_UNICODE[0] = 0;
    dinfo.CARACTER_UNICODE[1] = 0;
    dinfo.CARACTER_UNICODE[2] = 0;
    dinfo.CARACTER_UNICODE[3] = 0;
    dinfo.BYTES_ESCRITOS = 0;
    dinfo.TIPO_DE_EVENTO = 0;
    dinfo.Campo_Teclas_modificadoras.HUBO_MODIFICADORES = 0;

    DWORD cantidad_leidos = 0;
    HANDLE consola_de_entrada = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD evento = {0};

    KEY_EVENT_RECORD* tecla = NULL;

    while (1) {
        if (
            ReadConsoleInputW(
                consola_de_entrada,
                &evento,
                1,
                &cantidad_leidos
            ) == FALSE
        ) return CapturarTeclaUTF8_Error_ReadConsoleInputW;

        if (evento.EventType == KEY_EVENT) {
            tecla = &(evento.Event.KeyEvent);

            if (dtecla.bKeyDown == TRUE) {
                switch (dtecla.wVirtualKeyCode)
                {
                    case VK_CONTROL:
                        dinfo.TIPO_DE_EVENTO = TECLA_CONTROL; break;
                    case VK_LCONTROL:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_CONTROL; break;
                    case VK_RCONTROL:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_CONTROL; break;

                    case VK_MENU:
                        dinfo.TIPO_DE_EVENTO = TECLA_ALT; break;
                    case VK_LMENU:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_ALT; break;
                    case VK_RMENU:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_ALT; break;

                    case VK_LWIN:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_OS; break;
                    case VK_RWIN:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_OS; break;

                    case VK_SHIFT:
                        dinfo.TIPO_DE_EVENTO = TECLA_SHIFT; break;
                    case VK_LSHIFT:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_SHIFT; break;
                    case VK_RSHIFT:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_SHIFT; break;

                    default:
                        dinfo.IZQUIERDA_O_DERECHA = 0;
                        switch (dtecla.wVirtualKeyCode)
                        {
                            case VK_ESCAPE: dinfo.TIPO_DE_EVENTO = TECLA_ESCAPE; break;
                            case VK_TAB:    dinfo.TIPO_DE_EVENTO = TECLA_TAB; break;
                            case VK_BACK:   dinfo.TIPO_DE_EVENTO = TECLA_BACKSPACE; break;
                            case VK_RETURN: dinfo.TIPO_DE_EVENTO = TECLA_ENTER; break;
                            case VK_DELETE: dinfo.TIPO_DE_EVENTO = TECLA_SUPRIMIR; break;
                            case VK_INSERT: dinfo.TIPO_DE_EVENTO = TECLA_INSERTAR; break;
                            case VK_UP:     dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_ARRIBA; break;
                            case VK_DOWN:   dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_ABAJO; break;
                            case VK_LEFT:   dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_IZ; break;
                            case VK_RIGHT:  dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_DE; break;
                            case VK_HOME:   dinfo.TIPO_DE_EVENTO = TECLA_INICIO; break;
                            case VK_END:    dinfo.TIPO_DE_EVENTO = TECLA_FIN; break;
                            case VK_PRIOR:  dinfo.TIPO_DE_EVENTO = TECLA_PAG_ARRIBA; break;
                            case VK_NEXT:   dinfo.TIPO_DE_EVENTO = TECLA_PAG_ABAJO; break;
                            case VK_F1: dinfo.TIPO_DE_EVENTO = TECLA_F1; break;
                            case VK_F2: dinfo.TIPO_DE_EVENTO = TECLA_F2; break;
                            case VK_F3: dinfo.TIPO_DE_EVENTO = TECLA_F3; break;
                            case VK_F4: dinfo.TIPO_DE_EVENTO = TECLA_F4; break;
                            case VK_F5: dinfo.TIPO_DE_EVENTO = TECLA_F5; break;
                            case VK_F6: dinfo.TIPO_DE_EVENTO = TECLA_F6; break;
                            case VK_F7: dinfo.TIPO_DE_EVENTO = TECLA_F7; break;
                            case VK_F8: dinfo.TIPO_DE_EVENTO = TECLA_F8; break;
                            case VK_F9: dinfo.TIPO_DE_EVENTO = TECLA_F9; break;
                            case VK_F10: dinfo.TIPO_DE_EVENTO = TECLA_F10; break;
                            case VK_F11: dinfo.TIPO_DE_EVENTO = TECLA_F11; break;
                            case VK_F12: dinfo.TIPO_DE_EVENTO = TECLA_F12; break;
                            case VK_F13: dinfo.TIPO_DE_EVENTO = TECLA_F13; break;
                            case VK_F14: dinfo.TIPO_DE_EVENTO = TECLA_F14; break;
                            case VK_F15: dinfo.TIPO_DE_EVENTO = TECLA_F15; break;
                            case VK_F16: dinfo.TIPO_DE_EVENTO = TECLA_F16; break;
                            case VK_F17: dinfo.TIPO_DE_EVENTO = TECLA_F17; break;
                            case VK_F18: dinfo.TIPO_DE_EVENTO = TECLA_F18; break;
                            case VK_F19: dinfo.TIPO_DE_EVENTO = TECLA_F19; break;
                            case VK_F20: dinfo.TIPO_DE_EVENTO = TECLA_F20; break;
                            case VK_F21: dinfo.TIPO_DE_EVENTO = TECLA_F21; break;
                            case VK_F22: dinfo.TIPO_DE_EVENTO = TECLA_F22; break;
                            case VK_F23: dinfo.TIPO_DE_EVENTO = TECLA_F23; break;
                            case VK_F24: dinfo.TIPO_DE_EVENTO = TECLA_F24; break;
                            default:     dinfo.TIPO_DE_EVENTO = TECLA_INDETERMINADA; break;
                        }
                }

                if (dtecla.uChar.UnicodeChar != L'\0') {
                    // produjo caracter Unicode.
                    Byte_t cantidad_de_bytes_escritos = 0;
                    Bool_t se_necesita_dos_WCHAR = No;
                    WCHAR par = dtecla.uChar.UnicodeChar;
                    WCHAR Caracter_UTF16[2] = {0};

                    Caracter_UTF16[0] = par;

                    if (par >= 0xd800 && par <= 0xdbff) {
                        se_necesita_dos_WCHAR = Si;

                        if (
                            ReadConsoleInputW(
                                consola_de_entrada,
                                &evento,
                                1,
                                &cantidad_leidos
                            ) == FALSE
                        ) return 0x02;

                        if (evento.EventType == KEY_EVENT) {
                            tecla = &(evento.Event.KeyEvent);

                            if (dtecla.bKeyDown == TRUE) {
                                par = dtecla.uChar.UnicodeChar;

                                if (par >= 0xdc00 && par <= 0xdfff)
                                    Caracter_UTF16[1] = par;
                                else
                                    return CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Suplente_No_Correspondiente; 
                            } else
                                return CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__KeyDown_Falso;
                        } else
                            return CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Sin_KeyEvent;
                    }

                    if (se_necesita_dos_WCHAR == Si) {
                        cantidad_de_bytes_escritos = (Byte_t)WideCharToMultiByte(
                            CP_UTF8,
                            0,
                            Caracter_UTF16,
                            2,
                            dinfo.CARACTER_UNICODE,
                            4,
                            NULL,
                            NULL
                        );
                    } else {
                        cantidad_de_bytes_escritos = (Byte_t)WideCharToMultiByte(
                            CP_UTF8,
                            0,
                            Caracter_UTF16,
                            1,
                            dinfo.CARACTER_UNICODE,
                            4,
                            NULL,
                            NULL
                        );
                    }

                    if (cantidad_de_bytes_escritos == 0)
                        return CapturarTeclaUTF8_Error_Escritos_Cero;
                    else
                        dinfo.BYTES_ESCRITOS = cantidad_de_bytes_escritos;

                    if (dinfo.TIPO_DE_EVENTO == TECLA_INDETERMINADA)
                        dinfo.TIPO_DE_EVENTO = TECLA_CARACTER;
                }

                if (dtecla.dwControlKeyState != 0) {
                    DWORD estado = dtecla.dwControlKeyState;
                    if (estado & RIGHT_ALT_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.ALT_DERECHA         = Si;
                    if (estado & LEFT_ALT_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.ALT_IZQUIERDA       = Si;
                    if (estado & RIGHT_CTRL_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.CTRL_DERECHA        = Si;
                    if (estado & LEFT_CTRL_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.CTRL_IZQUIERDA      = Si;
                    if (estado & SHIFT_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.SHIFT               = Si;
                    if (estado & NUMLOCK_ON)
                        dinfo.Campo_Teclas_modificadoras.NUM_LOCK_ACTIVO     = Si;
                    if (estado & CAPSLOCK_ON)
                        dinfo.Campo_Teclas_modificadoras.MAYUS_ACTIVO        = Si;
                    if (estado & SCROLLLOCK_ON)
                        dinfo.Campo_Teclas_modificadoras.SCROLL_LOCK_ACTIVO  = Si;
                    dinfo.Campo_Teclas_modificadoras.HUBO_MODIFICADORES = Si;
                } else
                    dinfo.Campo_Teclas_modificadoras.HUBO_MODIFICADORES = No;
                break;

            } else continue;
        }
    }

    #undef dtecla
    #undef dinfo
    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t CambiarCodigoDePagina(
    Byte_t CODIGO_DE_PAGINA,
    Byte_t CONSOLA_A_CAMBIAR
) {
    UINT CodPag = 0;

    switch (CODIGO_DE_PAGINA)
    {
        case CodPag_ANSI_SubProceso : CodPag = CP_THREAD_ACP;   break;
        case CodPag_ANSI_Predet     : CodPag = CP_ACP;          break;
        case CodPag_OEM_Predet      : CodPag = CP_OEMCP;        break;
        case CodPag_Macintosh       : CodPag = CP_MACCP;        break;
        case CodPag_Simbolos        : CodPag = CP_SYMBOL;       break;
        case CodPag_UTF7            : CodPag = CP_UTF7;         break;
        case CodPag_UTF8            : CodPag = CP_UTF8;         break;

        default:
            return CambiarCodigoDePagina_Error_Parametro_CodPag_Invalido;
    }

    if (CONSOLA_A_CAMBIAR == CONSOLA_OUTPUT) {
        if (SetConsoleOutputCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_SetConsoleOutputCP;
    } else if (CONSOLA_A_CAMBIAR == CONSOLA_INPUT) {
        if (SetConsoleCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_INPUT_SetConsoleCP;
    } else if (CONSOLA_A_CAMBIAR == (CONSOLA_OUTPUT | CONSOLA_INPUT)) {
        if (SetConsoleOutputCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP;
        if (SetConsoleCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleCP;
    } else
        return CambiarCodigoDePagina_Error_Parametro_Consola_Invalido;
    
    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t ObtenerCodigoDePagina(
    DATOS_DE_COD_PAG* DATOS
) {
    #define dDatos (*DATOS)
    if (DATOS == NULL)
        return GENERAL_Error_Puntero_NULL;

    UINT CodPag_entrada = GetConsoleCP();
    UINT CodPag_salida = GetConsoleOutputCP();
    Byte_t retorno = 0;

    if (CodPag_entrada == 0)
        retorno |= ObtenerCodigoDePagina_Error_GetConsoleCP_Entrada;       // 0x02
    if (CodPag_salida == 0)
        retorno |= ObtenerCodigoDePagina_Error_GetConsoleOutputCP_Salida;  // 0x04

    switch (CodPag_entrada) {
        case CP_THREAD_ACP: dDatos.COD_PAG_ENTRADA = CodPag_ANSI_SubProceso; break;
        case CP_ACP:        dDatos.COD_PAG_ENTRADA = CodPag_ANSI_Predet;     break;
        case CP_OEMCP:      dDatos.COD_PAG_ENTRADA = CodPag_OEM_Predet;      break;
        case CP_MACCP:      dDatos.COD_PAG_ENTRADA = CodPag_Macintosh;       break;
        case CP_SYMBOL:     dDatos.COD_PAG_ENTRADA = CodPag_Simbolos;        break;
        case CP_UTF7:       dDatos.COD_PAG_ENTRADA = CodPag_UTF7;            break;
        case CP_UTF8:       dDatos.COD_PAG_ENTRADA = CodPag_UTF8;            break;
        default:
            dDatos.COD_PAG_ENTRADA = CodPag_INDETERMINADO;
            retorno |= ObtenerCodigoDePagina_Error_CodPag_Entrada_Indeterminado; // 0x08
            break;
    }

    switch (CodPag_salida) {
        case CP_THREAD_ACP: dDatos.COD_PAG_SALIDA = CodPag_ANSI_SubProceso; break;
        case CP_ACP:        dDatos.COD_PAG_SALIDA = CodPag_ANSI_Predet;     break;
        case CP_OEMCP:      dDatos.COD_PAG_SALIDA = CodPag_OEM_Predet;      break;
        case CP_MACCP:      dDatos.COD_PAG_SALIDA = CodPag_Macintosh;       break;
        case CP_SYMBOL:     dDatos.COD_PAG_SALIDA = CodPag_Simbolos;        break;
        case CP_UTF7:       dDatos.COD_PAG_SALIDA = CodPag_UTF7;            break;
        case CP_UTF8:       dDatos.COD_PAG_SALIDA = CodPag_UTF8;            break;
        default:
            dDatos.COD_PAG_SALIDA = CodPag_INDETERMINADO;
            retorno |= ObtenerCodigoDePagina_Error_CodPag_Salida_Indeterminado; // 0x10
            break;
    }

    #undef dDatos
    return retorno;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t LimpiarConsola(
    Byte_t CONSOLA_A_LIMPIAR
) {
    //implementacio de Windows
    HANDLE Entrada_Estandar = NULL;
    HANDLE Salida_Estandar  = NULL;
    HANDLE Error_Estandar   = NULL;

    if (CONSOLA_A_LIMPIAR == CONSOLA_INPUT) {
        Entrada_Estandar = GetStdHandle(STD_INPUT_HANDLE);
        if (
            Entrada_Estandar == INVALID_HANDLE_VALUE ||
            Entrada_Estandar == NULL
        ) return LimpiarConsola_Error_GetStdHandle_stdIn;
        {
            DWORD modo = 0;
            if (GetConsoleMode(Entrada_Estandar, &modo) == FALSE)
                return LimpiarConsola_Error_stdIn_Sin_Consola;
        }

        if (FlushConsoleInputBuffer(Entrada_Estandar) == FALSE)
            return LimpiarConsola_Error_FlushConsoleInputBuffer_stdIn;
        
    } else if (CONSOLA_A_LIMPIAR == CONSOLA_OUTPUT) {
        Salida_Estandar = GetStdHandle(STD_OUTPUT_HANDLE);
        if (
            Salida_Estandar == INVALID_HANDLE_VALUE ||
            Salida_Estandar == NULL
        ) return LimpiarConsola_Error_GetStdHandle_stdOut;
        {
            DWORD Modo = 0;
            if (GetConsoleMode(Salida_Estandar, &Modo) == FALSE)
                return LimpiarConsola_Error_stdOut_Sin_Consola;
        }

        CONSOLE_SCREEN_BUFFER_INFO informacion_buffer_consola = {0};
        DWORD cantidad = 0;
        COORD inicio = {0, 0};

        if (GetConsoleScreenBufferInfo(Salida_Estandar, &informacion_buffer_consola) == FALSE)
            return LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdOut;

        DWORD Area_total = ((DWORD)informacion_buffer_consola.dwSize.Y) * ((DWORD)informacion_buffer_consola.dwSize.X);

        if (FillConsoleOutputCharacterA(
            Salida_Estandar,
            ' ',
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleCharacterA_stdOut;

        if (FillConsoleOutputAttribute(
            Salida_Estandar,
            informacion_buffer_consola.wAttributes,
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleAttribute_stdOut;

        if (SetConsoleCursorPosition(
            Salida_Estandar,
            inicio
        ) == FALSE) return LimpiarConsola_Error_SetCursor_stdOut;

    } else if (CONSOLA_A_LIMPIAR == CONSOLA_ERROR) {
        Error_Estandar  = GetStdHandle(STD_ERROR_HANDLE);
        if (
            Error_Estandar == INVALID_HANDLE_VALUE ||
            Error_Estandar == NULL
        ) return LimpiarConsola_Error_GetStdHandle_stdErr;
        {
            DWORD Modo = 0;
            if (GetConsoleMode(Error_Estandar, &Modo) == FALSE)
                return LimpiarConsola_Error_stdErr_Sin_Consola;
        }

        CONSOLE_SCREEN_BUFFER_INFO informacion_buffer_consola = {0};
        DWORD cantidad = 0;
        COORD inicio = {0, 0};

        if (GetConsoleScreenBufferInfo(Error_Estandar, &informacion_buffer_consola) == FALSE)
            return LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdErr;

        DWORD Area_total = ((DWORD)informacion_buffer_consola.dwSize.Y) * ((DWORD)informacion_buffer_consola.dwSize.X);

        if (FillConsoleOutputCharacterA(
            Error_Estandar,
            ' ',
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleCharacterA_stdErr;

        if (FillConsoleOutputAttribute(
            Error_Estandar,
            informacion_buffer_consola.wAttributes,
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleAttribute_stdErr;

        if (SetConsoleCursorPosition(
            Error_Estandar,
            inicio
        ) == FALSE) return LimpiarConsola_Error_SetCursor_stdErr;

    } else return LimpiarConsola_Error_Parametro_Invalido;


    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t Entrada(
    ENTRADA_PARAMs* CONFIGURACIONES_Y_PARAMETROS
) {

    #define dConfParams (*CONFIGURACIONES_Y_PARAMETROS)

    ///////////configuramos salida y entrada////////
    UINT entrada_antes;
    UINT salida_antes;
    if ((entrada_antes = GetConsoleCP()) == 0)
        return Entrada_Error_GetConsoleCP;
    if ((salida_antes = GetConsoleOutputCP()) == 0)
        return Entrada_Error_GetConsoleOutputCP;

    if (SetConsoleCP(CP_UTF8) == FALSE) {
        SetConsoleCP(entrada_antes);
        return Entrada_Error_SetConsoleCP;
    }
    if (SetConsoleOutputCP(CP_UTF8) == FALSE) {
        SetConsoleCP(entrada_antes);
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_SetConsoleOutputCP;
    }

    if (CONFIGURACIONES_Y_PARAMETROS == NULL)
        return GENERAL_Error_Puntero_NULL;
    /////////////////////////////////////////////////

    if (dConfParams._PUNTERO_BUFFER_DE_ENTRADA_ == NULL) {
        SetConsoleCP(entrada_antes);
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_Puntero_BufferEntrada_NULL;
    }

    char* buffer = dConfParams._PUNTERO_BUFFER_DE_ENTRADA_;

    if (dConfParams._LONGITUD_DEL_BUFFER_ < 2) {
        SetConsoleCP(entrada_antes);
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_LongitudBuffer_Menor_A_Dos;
    }

    size_t longitud = dConfParams._LONGITUD_DEL_BUFFER_;

    if (dConfParams._PERMITIR_CONFIGURACION_ == Si) {

        Bool_t prompt_predeterminado    = No;
        Bool_t mostrar_indicador        = No;
        Bool_t mostrar_prompt           = No;
        Bool_t usar_salida_especial     = No;
        Bool_t indicar_metodo_de_salida = No;
        Bool_t mostrar_mensaje          = No;
        const char* mensaje_de_usuario  = NULL;
        const char* prompt_de_usuario   = NULL;
        Byte_t metodo = 0;

        if (
            dConfParams.Campo_Configuracion.MOSTRAR_INDICADOR_DE_LONGITUD_USADA == Si
        ) mostrar_indicador = Si;

        if (
            dConfParams.Campo_Configuracion.MOSTRAR_PROMPT_DE_ENTRADA == Si
        ) mostrar_prompt = Si;

        if (mostrar_prompt == Si) {
            if (dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_ == NULL)
                prompt_predeterminado = Si;
            else
                prompt_de_usuario = dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_;
        }

        if (
            dConfParams.Campo_Configuracion.Campo_Avanzados.MOSTRAR_LISTA_DE_MENSAJES_ANTES_DE_LA_ENTRADA == Si
        ) mostrar_mensaje = Si;

        if (mostrar_mensaje) {
            if (dConfParams.Campo_Configuracion.Campo_Avanzados._LISTA_DE_MENSAJES_ == NULL)
                mostrar_mensaje = No;
            else
                mensaje_de_usuario = dConfParams.Campo_Configuracion.Campo_Avanzados._LISTA_DE_MENSAJES_;

            // TODO: implementar la verificación de que la lista de mensajes termine con un caracter nulo.
            {
                size_t longitud_de_listmensaje = dConfParams.Campo_Configuracion.Campo_Avanzados._LONGITUD_DE_LA_LISTA_;
                if (longitud_de_listmensaje < 2) {
                    SetConsoleCP(entrada_antes);
                    SetConsoleOutputCP(salida_antes);
                    return Entrada_Error_Longitud_Lista_Menor_A_Dos;
                }
                enum pasos {
                    NADA = 1,
                    CARACTER = 2,
                    TERMINADO = 3
                };
                Byte_t etapa = NADA;
                size_t i = 0;
                while (i < longitud_de_listmensaje) {
                    if (mensaje_de_usuario[i] == '\0') {
                        if (mensaje_de_usuario[i+1] == '\0') {
                            etapa = TERMINADO;
                            break;
                        }
                        else if (etapa == NADA) {
                            return Entrada_Error_Lista_Mensajes_Inicio_Con_Nulo;
                        }
                    } else {
                        etapa = CARACTER;
                    }
                    i++;
                }

                if (etapa != TERMINADO) {
                    SetConsoleCP(entrada_antes);
                    SetConsoleOutputCP(salida_antes);
                    return Entrada_Error_Lista_Mensajes_No_Termina_Con_Nulo;
                }
            }
        }

        if (
            dConfParams.Campo_Configuracion.Campo_Avanzados.USAR_METODO_DE_SALIDA_CON_TECLA_ESPECIAL == Si
        ) usar_salida_especial = Si;

        if (
            (dConfParams.Campo_Configuracion.Campo_Avanzados._TECLA_ESPECIAL_DE_SALIDA_)
            !=
            TECLA_CARACTER
            &&
            (dConfParams.Campo_Configuracion.Campo_Avanzados._TECLA_ESPECIAL_DE_SALIDA_)
            !=
            0
        ) metodo = dConfParams.Campo_Configuracion.Campo_Avanzados._TECLA_ESPECIAL_DE_SALIDA_;
        else metodo = TECLA_TAB;

        if (
            dConfParams.Campo_Configuracion.Campo_Avanzados.INDICAR_METODO_DE_SALIDA_AL_USUARIO == Si
        ) indicar_metodo_de_salida = Si;


        EVENTO_TECLA evento = {0};
        size_t i = 0;
        if (mostrar_indicador) {
            while (1) {
                if (LimpiarConsola(CONSOLA_OUTPUT) != 0) {
                    SetConsoleCP(entrada_antes);
                    SetConsoleOutputCP(salida_antes);
                    return Entrada_Error_LimpiarConsola;
                }

                if (mostrar_mensaje) {
                    size_t iterador = 0;
                    while (1) {
                        if (mensaje_de_usuario[iterador] != '\0') {
                            Byte_t error_escribir = Escribir(
                                &(mensaje_de_usuario[iterador]),
                                1,
                                NULL,
                                CONSOLA_OUTPUT
                            );
                            if (error_escribir != 0 && error_escribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales) {
                                SetConsoleCP(entrada_antes);
                                SetConsoleOutputCP(salida_antes);
                                return Entrada_Error_Escribir_Lista_De_Mensajes;
                            }
                        }

                        else if (mensaje_de_usuario[iterador+1] == '\0')
                            break;
                        iterador++;
                    }
                }

                if (indicar_metodo_de_salida) {
                    Imprimir("[", NULL);
                    ImprimirTipoTecla(metodo);
                    Imprimir("]: salir\n", NULL);
                }

                Imprimir("límite [", NULL);
                Imprimir("%int/", &i);
                Imprimir("%int]\n", &longitud);

                if (mostrar_prompt) {
                    if (prompt_predeterminado)
                        Imprimir(">>> ", NULL);
                    else
                        Imprimir("%s", (void*)prompt_de_usuario);
                }

                Imprimir("%s", (void*)buffer);

                do {
                    if (CapturarTeclaUTF8(&evento) != 0) {
                        SetConsoleCP(entrada_antes);
                        SetConsoleOutputCP(salida_antes);
                        return Entrada_Error_CapturarTeclaUTF8;
                    }

                    if (usar_salida_especial) {
                        if (evento.TIPO_DE_EVENTO == metodo) {
                            SetConsoleCP(entrada_antes);
                            SetConsoleOutputCP(salida_antes);
                            return Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial;
                        }
                    }
                } while (
                    evento.TIPO_DE_EVENTO != TECLA_CARACTER  &&
                    evento.TIPO_DE_EVENTO != TECLA_ENTER     &&
                    evento.TIPO_DE_EVENTO != TECLA_BACKSPACE
                );

                if (
                    evento.TIPO_DE_EVENTO == TECLA_BACKSPACE ||
                    (evento.CARACTER_UNICODE)[0] == '\b' 
                ) {
                    if (i > 0) {
                        while (1) {
                            if ((buffer[i-1] & 0xC0) == 0x80) {
                                i--;
                                buffer[i] = 0x00;
                            } else {
                                i--;
                                buffer[i] = 0x00;
                                break;
                            }
                        }
                    }
                } else if (
                    evento.TIPO_DE_EVENTO == TECLA_ENTER    ||
                    (evento.CARACTER_UNICODE)[0] == '\n'  ||
                    (evento.CARACTER_UNICODE)[0] == '\r'
                ) {
                    break;
                } else {
                    if ((i + evento.BYTES_ESCRITOS) < longitud) {
                        Byte_t escritos = 0;
                        while (escritos < evento.BYTES_ESCRITOS) {
                            buffer[i] = (evento.CARACTER_UNICODE[escritos]);
                            escritos++;
                            i++;
                        }
                        buffer[i] = 0x00;
                    }
                }

            }

        } else {
            if (mostrar_mensaje) {
                size_t iterador = 0;
                while (1) {
                    if (mensaje_de_usuario[iterador] != '\0') {
                        Byte_t error_escribir = Escribir(
                            &(mensaje_de_usuario[iterador]),
                            1,
                            NULL,
                            CONSOLA_OUTPUT
                        );
                        if (error_escribir != 0 && error_escribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales) {
                            SetConsoleCP(entrada_antes);
                            SetConsoleOutputCP(salida_antes);
                            return Entrada_Error_Escribir_Lista_De_Mensajes;
                        }
                    }
                    else if (mensaje_de_usuario[iterador+1] == '\0')
                        break;
                    iterador++;
                }
            }

            if (indicar_metodo_de_salida) {
                Imprimir("[", NULL);
                ImprimirTipoTecla(metodo);
                Imprimir("]: salir\n", NULL);
            }
            if (mostrar_prompt) {
                if (prompt_predeterminado)
                    Imprimir(">>> ", NULL);
                else
                    Imprimir("%s", (void*)prompt_de_usuario);
            }
            while (1) {

                do {
                    if (CapturarTeclaUTF8(&evento) != 0) {
                        SetConsoleCP(entrada_antes);
                        SetConsoleOutputCP(salida_antes);
                        return Entrada_Error_CapturarTeclaUTF8;
                    }

                    if (usar_salida_especial) {
                        if (evento.TIPO_DE_EVENTO == metodo) {
                            SetConsoleCP(entrada_antes);
                            SetConsoleOutputCP(salida_antes);
                            return Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial;
                        }
                    }
                } while (
                    evento.TIPO_DE_EVENTO != TECLA_CARACTER  &&
                    evento.TIPO_DE_EVENTO != TECLA_ENTER     &&
                    evento.TIPO_DE_EVENTO != TECLA_BACKSPACE
                );

                if (
                    evento.TIPO_DE_EVENTO == TECLA_BACKSPACE ||
                    (evento.CARACTER_UNICODE)[0] == '\b' 
                ) {
                    if (i > 0) {
                        while (1) {
                            if ((buffer[i-1] & 0xC0) == 0x80) {
                                i--;
                                buffer[i] = 0x00;
                            } else {
                                i--;
                                buffer[i] = 0x00;
                                break;
                            }
                        }
                        Imprimir("\b \b", NULL);
                    }
                } else if (
                    evento.TIPO_DE_EVENTO == TECLA_ENTER    ||
                    (evento.CARACTER_UNICODE)[0] == '\n'  ||
                    (evento.CARACTER_UNICODE)[0] == '\r'
                ) {
                    break;
                } else {
                    if ((i + evento.BYTES_ESCRITOS) < longitud) {
                        Byte_t escritos = 0;
                        while (escritos < evento.BYTES_ESCRITOS) {
                            buffer[i] = (evento.CARACTER_UNICODE[escritos]);
                            escritos++;
                            i++;
                        }
                        buffer[i] = 0x00;
                        Imprimir("%s", (void*)((buffer+i)-escritos));
                    }
                }

            } 
        }

    } else { /********************************************************/
        // Estandar de la función.
        EVENTO_TECLA evento = {0};
        size_t i = 0;

        while (1) {

            do {
                if (CapturarTeclaUTF8(&evento) != 0) {
                    SetConsoleCP(entrada_antes);
                    SetConsoleOutputCP(salida_antes);
                    return Entrada_Error_CapturarTeclaUTF8;
                }
            } while (
                evento.TIPO_DE_EVENTO != TECLA_CARACTER  &&
                evento.TIPO_DE_EVENTO != TECLA_ENTER     &&
                evento.TIPO_DE_EVENTO != TECLA_BACKSPACE
            );

            if (
                evento.TIPO_DE_EVENTO == TECLA_BACKSPACE ||
                (evento.CARACTER_UNICODE)[0] == '\b' 
            ) {
                if (i > 0) {
                    while (1) {
                        if ((buffer[i-1] & 0xC0) == 0x80) {
                            i--;
                            buffer[i] = 0x00;
                        } else {
                            i--;
                            buffer[i] = 0x00;
                            break;
                        }
                    }
                    Imprimir("\b \b", NULL);
                }
            } else if (
                evento.TIPO_DE_EVENTO == TECLA_ENTER    ||
                (evento.CARACTER_UNICODE)[0] == '\n'  ||
                (evento.CARACTER_UNICODE)[0] == '\r'
            ) {
                break;
            } else {
                if ((i + evento.BYTES_ESCRITOS) < longitud) {
                    Byte_t escritos = 0;
                    while (escritos < evento.BYTES_ESCRITOS) {
                        buffer[i] = (evento.CARACTER_UNICODE[escritos]);
                        escritos++;
                        i++;
                    }
                    buffer[i] = 0x00;
                    Imprimir("%s", (void*)((buffer+i)-escritos));
                }
            }

        } 
    } //>>>> >>>> >>>> >>>> aquí termina el ELSE <<<< <<<< <<<< <<<<//

    if (SetConsoleCP(entrada_antes) == FALSE) {
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_SetConsoleCP;
    }
    if (SetConsoleOutputCP(salida_antes) == FALSE)
        return Entrada_Error_SetConsoleOutputCP;

    #undef BIT_0
    #undef BIT_1
    #undef BIT_2
    #undef BIT_3
    #undef dConfParams

    return 0x00;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t Escribir(
    const char*   BUFFER_DE_TEXTO_C,
    size_t  CANTIDAD_DE_BYTES_A_ESCRIBIR,
    Sint_t* CANTIDAD_DE_BYTES_ESCRITOS,
    Byte_t  CONSOLA_OUTPUT_O_ERROR
) {
    if (BUFFER_DE_TEXTO_C == NULL)
        return GENERAL_Error_Puntero_NULL;

    Byte_t retorno = 0;

    DWORD escritos = 0;
    HANDLE consola;
    if (CONSOLA_OUTPUT_O_ERROR == CONSOLA_OUTPUT)
        consola = GetStdHandle(STD_OUTPUT_HANDLE);
    else if (CONSOLA_OUTPUT_O_ERROR == CONSOLA_ERROR)
        consola = GetStdHandle(STD_ERROR_HANDLE);
    else
        return Escribir_Error_Param_Invalido;

    if (
        consola == INVALID_HANDLE_VALUE ||
        consola == NULL
    ) return Escribir_Error_GetStdHandle;

    retorno = (Bool_t)WriteFile(
        consola,
        BUFFER_DE_TEXTO_C,
        (DWORD)CANTIDAD_DE_BYTES_A_ESCRIBIR,
        &escritos,
        NULL
    );

    if (!retorno)
        retorno = Escribir_Error_WriteFile;
    else if (escritos != (DWORD)CANTIDAD_DE_BYTES_A_ESCRIBIR)
        retorno = Escribir_ErrorNOFATAL_Escritos_No_Iguales;
    else
        retorno = 0;

    if (CANTIDAD_DE_BYTES_ESCRITOS != NULL)
        *CANTIDAD_DE_BYTES_ESCRITOS += (Sint_t)escritos;

    return retorno;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Sint_t Imprimir(
    const char* TEXTO_C,
    void* PUNTERO_ARGUMENTO_O_NULL
) {
    #define C(iterador) TEXTO_C[bytes+iterador]
    if (TEXTO_C == NULL)
        return 0;
    Byte_t tipo_de_repr = 0;
    { // obtenemos el tipo de representación interna.
        signed char _referencia_ = -5;
        Byte_t* interno = (Byte_t*)&_referencia_;

        if ((Byte_t)(*interno) == 0b10000101)
            tipo_de_repr = _SIGNO_Y_MAGNITUD_;
        else if ((Byte_t)(*interno) == 0b11111010)
            tipo_de_repr = _COMPLEMENTO_UNO_;
        else
            tipo_de_repr = _COMPLEMENTO_DOS_;
    }

    Uint_t bytes = 0;
    Sint_t Cantidad_escritos = 0;  
    Byte_t RetEscribir = 0;

    while (1) {
        if (TEXTO_C[bytes] == 0x00) 
            break;  
        else {
            if (TEXTO_C[bytes] == '%') {
                Bool_t exito = Si;

                goto saltear_logica_puntero_nulo;

                puntero_nulo:
                RetEscribir = Escribir("NULL", 4, NULL, CONSOLA_OUTPUT);
                if (
                    RetEscribir != 0 &&
                    RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                ) return -(Cantidad_escritos); 
                goto volver;

                saltear_logica_puntero_nulo:    

                if (TEXTO_C[bytes+1] == 's' || TEXTO_C[bytes+1] == 'S') {  
                    if (PUNTERO_ARGUMENTO_O_NULL == NULL)  
                        goto puntero_nulo;  

                    Uint_t i = 0;  
                    char* _nuevoTEXTO_C = (char*)PUNTERO_ARGUMENTO_O_NULL;  

                    while (1) {  
                        if (_nuevoTEXTO_C[i] == 0x00)  
                            break; 
                        RetEscribir = Escribir(
                            (const char*)&(_nuevoTEXTO_C[i]),  
                            1,
                            (&Cantidad_escritos),
                            CONSOLA_OUTPUT
                        );
                        if (
                            RetEscribir != 0 &&
                            RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                        ) return -(Cantidad_escritos);
                        i++;  
                    }  
                } else if (TEXTO_C[bytes+1] == 'c' || TEXTO_C[bytes+1] == 'C') {  
                    if (PUNTERO_ARGUMENTO_O_NULL == NULL)  
                        goto puntero_nulo;  

                    char _nuevo_caracter_ = *((char*)(PUNTERO_ARGUMENTO_O_NULL));  


                    RetEscribir = Escribir(
                        (const char*)&_nuevo_caracter_,  
                        1,
                        (&Cantidad_escritos),
                        CONSOLA_OUTPUT
                    );
                    if (
                        RetEscribir != 0 &&
                        RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                    ) return -(Cantidad_escritos);  
                } else if (TEXTO_C[bytes+1] == 'x' || TEXTO_C[bytes+1] == 'X') {  
                    if (PUNTERO_ARGUMENTO_O_NULL == NULL)  
                        goto puntero_nulo;  

                    Bool_t minuscula = Si;  
                    if (TEXTO_C[bytes+1] == 'X')  
                        minuscula = No;  

                    Byte_t _hex_ = *((Byte_t*)(PUNTERO_ARGUMENTO_O_NULL));  

                    Byte_t  nibble_alto = _hex_ >> 4;  
                    Byte_t  nibble_bajo = _hex_ & 0x0f;  
                    char* nibble = NULL;  
                    Bool_t  termino = No;  

                    while (1) {  
                        if (termino == No)  
                            nibble = (char*)&nibble_alto;  
                        else  
                            nibble = (char*)&nibble_bajo;  

                        if (*nibble < 0x0A)  
                            *nibble += 0x30;  
                        else {  
                            if (minuscula)  
                                *nibble += 0x57;  
                            else  
                                *nibble += 0x37;  
                        }  


                        RetEscribir = Escribir(
                            (const char*)nibble,  
                            1,
                            (&Cantidad_escritos),
                            CONSOLA_OUTPUT
                        );
                        if (
                            RetEscribir != 0 &&
                            RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                        ) return -(Cantidad_escritos); 

                        if (termino == Si)  
                            break;  
                        else  
                            termino = Si;  

                    }  
                } else if (TEXTO_C[bytes+1] == 'b' || TEXTO_C[bytes+1] == 'B') {  
                    if (PUNTERO_ARGUMENTO_O_NULL == NULL)  
                        goto puntero_nulo;

                    Byte_t mascara = 0b10000000;  
                    Byte_t _bin_ = *((Byte_t*)(PUNTERO_ARGUMENTO_O_NULL));  

                    for (Byte_t i = 0; i < 8; i++) {  
                        if ((mascara >> i)&(_bin_)) { 
                            RetEscribir = Escribir(
                                "1",  
                                1,
                                (&Cantidad_escritos),
                                CONSOLA_OUTPUT
                            );
                            if (
                                RetEscribir != 0 &&
                                RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                            ) return -(Cantidad_escritos); 
                        } else {  
                            RetEscribir = Escribir(
                                "0",  
                                1,
                                (&Cantidad_escritos),
                                CONSOLA_OUTPUT
                            );
                            if (
                                RetEscribir != 0 &&
                                RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                            ) return -(Cantidad_escritos); 
                        }  
                    }  
                } else if (
                    (C(1) == 'i' && C(2) == 'n' && C(3) == 't')
                    ||
                    (C(1) == 'u' && C(2) == 'i' && C(3) == 'n' && C(4) == 't')
                ) {
                    if (PUNTERO_ARGUMENTO_O_NULL == NULL) {
                        if (C(1) == 'i')
                            bytes+=2;
                        else
                            bytes+=3;
                        goto puntero_nulo;
                    }
                    char numero_texto[12] = {0};
                    Uint_t i = 11;

                    if (C(1) == 'i') {
                        

                        Bool_t es_negativo = No;
                        bytes+=2;
                        Sint_t numero = *((Sint_t*)(PUNTERO_ARGUMENTO_O_NULL));
                        Uint_t numero_negativo = 0;

                        if (numero < 0) {
                            if (tipo_de_repr == _SIGNO_Y_MAGNITUD_)
                                if (sizeof(Sint_t) == 1)
                                    numero = (numero & 0x7f);
                                else if (sizeof(Sint_t) == 2)
                                    numero = (numero & 0x7fff);
                                else if (sizeof(Sint_t) == 8)
                                    numero = (numero & 0x7fffffffffffffff);
                                // sino es ninguna de las otras, entonces es la general.
                                else
                                    numero = (numero & 0x7fffffff);
                                //
                            else if (tipo_de_repr == _COMPLEMENTO_UNO_)
                                numero_negativo = (Uint_t)~numero;
                            else
                                numero_negativo = ((Uint_t)~numero)+1;

                            es_negativo = Si;
                        } else {
                            numero_negativo = (Uint_t)numero;
                        }

                        if (tipo_de_repr != _SIGNO_Y_MAGNITUD_) {
                            do {
                                numero_texto[i] = '0'+(numero_negativo%10);

                                numero_negativo /= 10;

                                i--;
                            } while (numero_negativo != 0);
                        } else {
                            do {
                                numero_texto[i] = '0'+(numero%10);

                                numero /= 10;

                                i--;
                            } while (numero != 0);
                        }

                        if (es_negativo == Si) {
                            numero_texto[i] = '-';
                            i--;
                        }
                    } else {
                        bytes+=3;
                        Uint_t numero = *((Uint_t*)(PUNTERO_ARGUMENTO_O_NULL));

                        do {
                            numero_texto[i] = '0'+(numero%10);

                            numero /= 10;

                            i--;
                        } while (numero != 0);
                    }

                    while (i < 11) {
                        i++;
                        RetEscribir = Escribir(
                            (const char*)&(numero_texto[i]),
                            1,
                            (&Cantidad_escritos),
                            CONSOLA_OUTPUT
                        );
                        if (
                            RetEscribir != 0 &&
                            RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                        ) return -(Cantidad_escritos);
                    }
                }
                else { 
                    RetEscribir = Escribir(
                        (const char*)&(TEXTO_C[bytes]),  
                        1,
                        (&Cantidad_escritos),
                        CONSOLA_OUTPUT
                    );
                    if (
                        RetEscribir != 0 &&
                        RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                    ) return -(Cantidad_escritos);
                    exito = No;
                }

                if (exito == No)
                    bytes++;
                else {
                    volver:
                        bytes+=2;
                }
                continue;  
            } else {  
                RetEscribir = Escribir(
                    (const char*)&(TEXTO_C[bytes]),  
                    1,
                    (&Cantidad_escritos),
                    CONSOLA_OUTPUT
                );
                if (
                    RetEscribir != 0 &&
                    RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                ) return -(Cantidad_escritos);
            }  
        }  
        bytes++;  
    }  

    return +(Cantidad_escritos);
    #undef C
}



//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//
//
//=======================
