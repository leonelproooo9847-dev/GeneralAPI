#ifndef API_GENERAL_H
    #define API_GENERAL_H "NumCab: 0"
    #define CAMBIO_API_GENERAL 1

    #include "DefGeneral.h"
    #include "Para_Windows/DefErrorWin.h"

    // estructuras:
    /*----------------------------------------------------------------------------*/

    typedef struct _COMPROBACION_PARAMs {
        struct {
            const char* _LISTA_DE_TEXTO_C_;
            size_t  _LONGITUD_DE_LA_LISTA_;
        } Campo_datos_de_entrada;
        struct {
            size_t* _LISTA_DE_SIZEs__GUARDADO_DE_INDICES_;
            size_t  _CANTIDAD_DE_SIZEs_;
        } Campo_datos_de_salida;
    } COMPROBACION_PARAMs;

    // funciones:
    /*----------------------------------------------------------------------------*/

    Byte_t SacarDirectorioActual(
        char*  UBICACION_ACTUAL_DE_ESTE_ARCHIVO_entrada,
        char*  UBICACION_MODIFICADA_resultado,
        size_t LONGITUD_DEL_BUFFER_DE_RESULTADO,
        Bool_t DEJAR_BARRA_INVERTIDA
    );
    //=========================================================================
    Byte_t LimpiarBuffer(
        Byte_t*     ESTRUCTURA,
        size_t      CANTIDAD_DE_BYTES
    );
    //=========================================================================
    Byte_t TipoReprDeSignos();
    //=========================================================================
    Byte_t CopiarBuffer(
        void* BUFFER_ORIGEN,
        void* BUFFER_DESTINO,
        size_t LONGITUD_DEL_BUFFER_ORIGEN,
        size_t LONGITUD_DEL_BUFFER_DESTINO
    );
    Byte_t ComprobarListaDeTexto(
        COMPROBACION_PARAMs* PARAMETROS
    );

#endif
