#ifndef LIB_WIN_H
    #define LIB_WIN_H "NumCab: No se necesita"

    #include <stddef.h>
    #include "../DefGeneral.h"
    #include "../DefTipos.h"
    #include "DefErrorWin.h"
    #include "LibProcesosWin.h"
    #include "MensajeErrorWin.h"
    #include "Entrada_y_Salida/DefEstruct.h"
    #include "Entrada_y_Salida/DefCodPag.h"
    #include "Entrada_y_Salida/DefTeclas.h"
    #include "Entrada_y_Salida/EntradaSalidaWin.h"

    #define VERIFICAR_CAMBIOS Si

    #if VERIFICAR_CAMBIOS
        #if !(CAMBIO_DEF_GENERAL == CAMBIO_DEF_TIPOS == CAMBIO_DEF_ERROR_WIN == CAMBIO_LIB_PROCESOS_WIN == CAMBIO_LIBP_WIN == CAMBIO_MENSAJE_ERROR_WIN == CAMBIO_DEF_ESTRUCT == CAMBIO_DEF_COD_PAG == CAMBIO_DEF_TECLAS == CAMBIO_ENTRADA_SALIDA_WIN)
            #warning "LibWin.h: Cambios en los archivos de cabecera relacionados no son consistentes."
        #endif
    #endif

    #undef VERIFICAR_CAMBIOS
#endif // fin
