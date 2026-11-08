#ifndef MENSAJE_ERROR_WIN_H
    #define MENSAJE_ERROR_WIN_H "NumCab: 5"
    #define CAMBIO_MENSAJE_ERROR_WIN 0

    #include "../DefGeneral.h"
    #include "DefErrorWin.h"

    void ImprimirMensajeDeError(
        void*  PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR,
        Byte_t FUNCION_ESPECIFICA_DEL_ERROR
    );
#endif
