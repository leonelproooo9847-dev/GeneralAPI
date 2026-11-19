// DefTipos.h
#ifndef TIPOS_CAB_H
    #define TIPOS_CAB_H "NumCab: 2"
    #define CAMBIO_DEF_TIPOS 3

    #define SOLO_64BIT_SIN_SIGNO 2
    #define SOLO_64BIT_CON_SIGNO 3
    /* @attention: Esta cabecera no- *\
    |  garantiza seguridad y consis-  |
    |  tencia entre implementaciones. |
    |                                 |
    |  @note: Esta cabecera solo      |
    |  será en español.               |
    |                                 |
    |  pd: Me cuesta hacerlo en el    |
    |  celular :P                     |
    \*                               */ 

    #if defined(__GNUC__) || defined(__clang__)

        #if __CHAR_BIT__ == 8
            // Con Signos
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __INT8_TYPE__
                typedef __INT8_TYPE__ S8;
            #else
                #error "'__INT8_TYPE__' no está definido"
            #endif

            #ifdef __INT16_TYPE__
                typedef __INT16_TYPE__ S16;
            #else
                #error "'__INT16_TYPE__' no está definido"
            #endif

            #ifdef __INT32_TYPE__
                typedef __INT32_TYPE__ S32;
            #else
                #error "'__INT32_TYPE__' no está definido"
            #endif

            #ifdef __INT64_TYPE__
                typedef __INT64_TYPE__ S64;
            #else
                #warning "'__INT64_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII


            // Sin Signos
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __UINT8_TYPE__
                typedef __UINT8_TYPE__ U8;
            #else
                #error "'__UINT8_TYPE__' no está definido"
            #endif

            #ifdef __UINT16_TYPE__
                typedef __UINT16_TYPE__ U16;
            #else
                #error "'__UINT16_TYPE__' no está definido"
            #endif

            #ifdef __UINT32_TYPE__
                typedef __UINT32_TYPE__ U32;
            #else
                #error "'__UINT32_TYPE__' no está definido"
            #endif

            #ifdef __UINT64_TYPE__
                typedef __UINT64_TYPE__ U64;
            #else
                #warning "'__UINT64_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif

            #if defined __UINTPTR_TYPE__
                typedef __UINTPTR_TYPE__ UPTR;
                #define UPTR_DEFINIDO "esta definido"
            #else
                #warning "'__UINTPTR_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif

            #if defined __SIZEOF_POINTER__
                #if defined __SIZEOF_INT__ && !(defined UPTR_DEFINIDO)
                    #if __SIZEOF_POINTER__ == __SIZEOF_INT__
                        typedef unsigned int UPTR;
                        #define UPTR_DEFINIDO "esta definido"
                    #endif
                #endif
                #if defined __SIZEOF_LONG__ && !(defined UPTR_DEFINIDO)
                    #if __SIZEOF_POINTER__ == __SIZEOF_LONG__
                        typedef unsigned long UPTR;
                        #define UPTR_DEFINIDO "esta definido"
                    #endif
                #endif
                #if defined __SIZEOF_LONG_LONG__ && !(defined UPTR_DEFINIDO)
                    #if __SIZEOF_POINTER__ == __SIZEOF_LONG_LONG__
                        typedef unsigned long long UPTR;
                        #define UPTR_DEFINIDO "esta definido"
                    #endif
                #endif
            #endif

            #if !(defined UPTR_DEFINIDO)    
                #error "no se pudo definir UPTR"
            #endif
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
        
            #if defined(__INT64_TYPE__) && defined(__UINT64_TYPE__)
                #define ESTA_DISPONIBLE_64BIT 1
            #elif defined(__INT64_TYPE__) && !(defined(__UINT64_TYPE__))
                #define ESTA_DISPONIBLE_64BIT SOLO_64BIT_CON_SIGNO
            #elif !(defined(__INT64_TYPE__)) && defined(__UINT64_TYPE__)
                #define ESTA_DISPONIBLE_64BIT SOLO_64BIT_SIN_SIGNO
            #else
                #define ESTA_DISPONIBLE_64BIT 0
            #endif
        #else
            #error "'__CHAR_BIT__' no es de 8 bit"
        #endif
    #elif defined(_MSC_VER)
        // TODO: COMPLETAR PARA MSVC
    #else
        #error "Sin soporte para este compilador"
    #endif
#endif
