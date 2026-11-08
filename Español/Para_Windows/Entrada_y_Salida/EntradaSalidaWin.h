#ifndef ENTRADA_SALIDA_WIN_H
    #define ENTRADA_SALIDA_WIN_H "NumCab: 9"
    #define CAMBIO_ENTRADA_SALIDA_WIN 2

    // apartado de inclusiones:
    #include "../../DefGeneral.h"
    #include "../DefErrorWin.h"
    #include "DefTeclas.h"
    #include "DefEstruct.h"
    #include "DefCodPag.h"


    // definiciones de funciones:
    //=========================================================================
    void ImprimirTipoTecla(
        Byte_t TECLA_ESPECIAL_A_IMPRIMIR
    );
    //=========================================================================
    Byte_t CapturarTeclaUTF8(
        EVENTO_TECLA* INFORMACION_DE_LA_TECLA
    );
    //=========================================================================
    Byte_t CambiarCodigoDePagina(
        Byte_t CODIGO_DE_PAGINA,
        Byte_t CONSOLA_A_CAMBIAR
    );
    //=========================================================================
    Byte_t ObtenerCodigoDePagina(
        DATOS_DE_COD_PAG* DATOS
    );
    //=========================================================================
    Byte_t LimpiarConsola(
        Byte_t CONSOLA_A_LIMPIAR
    );
    //=========================================================================
    Byte_t Entrada(
        ENTRADA_PARAMs* CONFIGURACIONES_Y_PARAMETROS
    );
    //=========================================================================
    Byte_t Escribir(
        const char*   BUFFER_DE_TEXTO_C_,
        size_t  CANTIDAD_DE_BYTES_A_ESCRIBIR,
        Sint_t* CANTIDAD_DE_BYTES_ESCRITOS,
        Byte_t  CONSOLA_OUTPUT_O_ERROR
    );
    //=========================================================================
    Sint_t Imprimir(
        const char* TEXTO_C,
        void* PUNTERO_ARGUMENTO_O_NULL
    );
#endif
