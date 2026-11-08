
#include "APIGeneral.h"

Byte_t SacarDirectorioActual(
    char*  UBICACION_ACTUAL_DE_ESTE_ARCHIVO_entrada,
    char*  UBICACION_MODIFICADA_resultado,
    size_t LONGITUD_DEL_BUFFER_DE_RESULTADO,
    Bool_t DEJAR_BARRA_INVERTIDA
) {
    if (
        UBICACION_ACTUAL_DE_ESTE_ARCHIVO_entrada   == NULL ||
        UBICACION_MODIFICADA_resultado             == NULL
    )
        return SacarDirectorioActual_Error_Punteros_NULLs;

    if (DEJAR_BARRA_INVERTIDA == 0)
        DEJAR_BARRA_INVERTIDA = No;
    size_t i_r = 0;

    {
        size_t i_e = 0;

        while (UBICACION_ACTUAL_DE_ESTE_ARCHIVO_entrada[i_e] != 0x00)
            i_e++;

        if (i_e >= LONGITUD_DEL_BUFFER_DE_RESULTADO)
            return SacarDirectorioActual_Error_Longitud_Corta;

        while (UBICACION_ACTUAL_DE_ESTE_ARCHIVO_entrada[i_r] != 0x00) {
            UBICACION_MODIFICADA_resultado[i_r] = UBICACION_ACTUAL_DE_ESTE_ARCHIVO_entrada[i_r];
            i_r++;
        }
        UBICACION_MODIFICADA_resultado[i_r] = 0x00;
    }

    while (i_r != 0) {
        if (
            UBICACION_MODIFICADA_resultado[i_r] == '\\' ||
            UBICACION_MODIFICADA_resultado[i_r] == '/'
        ) {
            if (DEJAR_BARRA_INVERTIDA == No)
                UBICACION_MODIFICADA_resultado[i_r] = 0x00;

            break;
        } else {
            UBICACION_MODIFICADA_resultado[i_r] = 0x00;
        }
        i_r--;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t LimpiarBuffer(
    Byte_t*     ESTRUCTURA,
    size_t      CANTIDAD_DE_BYTES
) {
    if (ESTRUCTURA == NULL)
        return GENERAL_Error_Puntero_NULL;

    size_t i = 0;
    while (i < CANTIDAD_DE_BYTES) {
        ESTRUCTURA[i] = 0x00;
        i++;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t TipoReprDeSignos() {
    signed char _referencia_ = -5;
    Byte_t* interno = (Byte_t*)&_referencia_;

    if ((Byte_t)(*interno) == 0b10000101)
        return _SIGNO_Y_MAGNITUD_;
    else if ((Byte_t)(*interno) == 0b11111010)
        return _COMPLEMENTO_UNO_;
    else
        return _COMPLEMENTO_DOS_;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t CopiarBuffer(
    void* BUFFER_ORIGEN,
    void* BUFFER_DESTINO,
    size_t LONGITUD_DEL_BUFFER_ORIGEN,
    size_t LONGITUD_DEL_BUFFER_DESTINO
) {
    if (
        BUFFER_DESTINO == NULL ||
        BUFFER_ORIGEN  == NULL
    ) return CopiarBuffer_Error_Punteros_Buffers_NULLs;

    if (
        LONGITUD_DEL_BUFFER_DESTINO == 0 ||
        LONGITUD_DEL_BUFFER_ORIGEN  == 0
    ) return CopiarBuffer_Error_Longitudes_Buffers_Cero;

    if (BUFFER_DESTINO != BUFFER_ORIGEN) {
        uintptr_t Origen  = (uintptr_t)BUFFER_ORIGEN;
        uintptr_t Destino = (uintptr_t)BUFFER_DESTINO;
        //==========================================================\ 
        if (Origen > Destino) 
            if ((Destino + LONGITUD_DEL_BUFFER_DESTINO) > Origen)
                return CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen;
        else
            if ((Origen + LONGITUD_DEL_BUFFER_ORIGEN) > Destino)
                return CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino;
        //==========================================================/
    } else return CopiarBuffer_Error_Mismos_Punteros_Origen_Destino;

    size_t i = 0;
    while (
        i < LONGITUD_DEL_BUFFER_DESTINO &&
        i < LONGITUD_DEL_BUFFER_ORIGEN
    ) {
        *(((Byte_t*)BUFFER_DESTINO) + i) = *(((Byte_t*)BUFFER_ORIGEN) + i);
        i++;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t ComprobarListaDeTexto(
    COMPROBACION_PARAMs* PARAMETROS
) {
    #define dParams (*PARAMETROS)
    if (PARAMETROS == NULL)
        return ComprobarListaDeTexto_Error_Estructura_NULL;
    
    if (dParams.Campo_datos_de_entrada._LISTA_DE_TEXTO_C_ == NULL)
        return ComprobarListaDeTexto_Error_Puntero_De_Lista_De_Texto_C_NULL;
    
    if (dParams.Campo_datos_de_entrada._LONGITUD_DE_LA_LISTA_ == 0)
        return ComprobarListaDeTexto_Error_Longitud_Cero;
    

    const char* lista_de_texto_c    = dParams.Campo_datos_de_entrada._LISTA_DE_TEXTO_C_;
    size_t  longitud_de_datos_ent   = dParams.Campo_datos_de_entrada._LONGITUD_DE_LA_LISTA_;
    size_t* lista_de_sizes          = NULL;
    size_t  cantidad_de_sizes       = 0;
    Bool_t  Guardar_cantidad        = Si;


    if (dParams.Campo_datos_de_salida._LISTA_DE_SIZEs__GUARDADO_DE_INDICES_ == NULL)
        Guardar_cantidad = No;

    if (Guardar_cantidad) {
        if (dParams.Campo_datos_de_salida._CANTIDAD_DE_SIZEs_ == 0)
            return ComprobarListaDeTexto_Error_Cantidad_De_Sizes_Cero;
    }

    if (Guardar_cantidad) {
        lista_de_sizes     = dParams.Campo_datos_de_salida._LISTA_DE_SIZEs__GUARDADO_DE_INDICES_;
        cantidad_de_sizes  = dParams.Campo_datos_de_salida._CANTIDAD_DE_SIZEs_;
    }

    enum PASOS {
        NADA,
        TEXTO_C,
        CARACTER_CERO,
        TERMINO
    };

    Byte_t ETAPAS = NADA;
    Byte_t CARACTER = 0;
    size_t i = 0;
    size_t sizes_i = 0;

    while (i < longitud_de_datos_ent) {
        CARACTER = (Byte_t)(lista_de_texto_c[i]);

        if (ETAPAS == NADA) {
            if (CARACTER == '\0')
                return ComprobarListaDeTexto_Error_Inicio_Con_Cero;
            ETAPAS = TEXTO_C;
            if (Guardar_cantidad) {
                if (sizes_i >= cantidad_de_sizes)
                    return ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes;
                lista_de_sizes[sizes_i] = i;
                sizes_i += 1;
            }
            continue;
        } else if (ETAPAS == TEXTO_C) {
            if (CARACTER == '\0')
                ETAPAS = CARACTER_CERO;

        } else if (ETAPAS == CARACTER_CERO) {
            if (CARACTER == '\0') {
                ETAPAS = TERMINO;
                break;
            }
            ETAPAS = TEXTO_C;
            if (Guardar_cantidad) {
                if (sizes_i >= cantidad_de_sizes)
                    return ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes;
                lista_de_sizes[sizes_i] = i;
                sizes_i += 1;
            }
            continue;
        }

        i++;
    }
    if (ETAPAS == NADA)
        return ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP1;
    else if (ETAPAS == TEXTO_C)
        return ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP2;
    else if (ETAPAS == CARACTER_CERO)
        return ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP3;

    return 0;
}
