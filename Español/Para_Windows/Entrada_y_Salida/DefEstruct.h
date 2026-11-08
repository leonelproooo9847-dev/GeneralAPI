#ifndef DEF_ESTRUCT_H
    #define DEF_ESTRUCT_H "NumCab: 7"
    #define CAMBIO_DEF_ESTRUCT 3

    #include "../../DefGeneral.h"

    typedef struct _EVENTO_TECLA {
        char   CARACTER_UNICODE[4];
        Byte_t BYTES_ESCRITOS;
        Byte_t TIPO_DE_EVENTO;
        Byte_t IZQUIERDA_O_DERECHA;
        struct {
            Bool_t  HUBO_MODIFICADORES;
            Bool_t  CTRL_DERECHA;
            Bool_t  CTRL_IZQUIERDA;
            Bool_t  ALT_DERECHA;
            Bool_t  ALT_IZQUIERDA;
            Bool_t  SHIFT;
            Bool_t  NUM_LOCK_ACTIVO;
            Bool_t  MAYUS_ACTIVO;
            Bool_t  SCROLL_LOCK_ACTIVO;
        } Campo_Teclas_modificadoras;
    } EVENTO_TECLA;


    /*----------------------------------------------------------------------------*/


    typedef struct _ENTRADA_PARAMs {
        char*   _PUNTERO_BUFFER_DE_ENTRADA_;
        size_t  _LONGITUD_DEL_BUFFER_;
        Bool_t  _PERMITIR_CONFIGURACION_;
        struct {
            Bool_t MOSTRAR_INDICADOR_DE_LONGITUD_USADA;
            Bool_t MOSTRAR_PROMPT_DE_ENTRADA;
            const char*  _PROMPT_DE_ENTRADA_TEXTO_C_;
            struct {
                Bool_t USAR_METODO_DE_SALIDA_CON_TECLA_ESPECIAL;
                Byte_t _TECLA_ESPECIAL_DE_SALIDA_;
                Bool_t INDICAR_METODO_DE_SALIDA_AL_USUARIO;
                Bool_t MOSTRAR_LISTA_DE_MENSAJES_ANTES_DE_LA_ENTRADA;
                const char*  _LISTA_DE_MENSAJES_;
                size_t       _LONGITUD_DE_LA_LISTA_;
            } Campo_Avanzados;
        } Campo_Configuracion;
    } ENTRADA_PARAMs;


    /*----------------------------------------------------------------------------*/


    typedef struct _DATOS_DE_COD_PAG {
        Byte_t COD_PAG_ENTRADA;
        Byte_t COD_PAG_SALIDA;
    } DATOS_DE_COD_PAG;
    
#endif
