// DefGeneral.h
#ifndef DEF_GNRAL_H 
    #define DEF_GNRAL_H "NumCab: 1"
    #define CAMBIO_DEF_GENERAL 1

    #define WINDOWS_32BIT 0x10
    #define WINDOWS_64BIT 0x20
    #define WINDOWS_GNRAL 0x40
    #define LINUX         0xb0

    #define _SIGNO_Y_MAGNITUD_ 0x01
    #define _COMPLEMENTO_UNO_  0x02
    #define _COMPLEMENTO_DOS_  0x03

    #if defined(_WIN64)
        #define Sistema_Operativo WINDOWS_64BIT
    #elif defined(_WIN32)
        #define Sistema_Operativo WINDOWS_32BIT
    #elif defined(__linux__)
        #define Sistema_Operativo LINUX
    #else
        #error "Entorno desconocido (solo LINUX y WINDOWS)"
    #endif

    #define Verdadero  0x01  
    #define Falso      0x00  

    #define Si Verdadero  
    #define No Falso  

    typedef signed   int  Sint_t;
    typedef unsigned int  Uint_t;
    typedef unsigned char Byte_t;
    typedef unsigned char Bool_t;
    typedef unsigned char BoolBit_t;

    #define Si_BIT0 0x01    // 0b00000001
    #define Si_BIT1 0x02    // 0b00000010
    #define Si_BIT2 0x04    // 0b00000100
    #define Si_BIT3 0x08    // 0b00001000
    #define Si_BIT4 0x10    // 0b00010000
    #define Si_BIT5 0x20    // 0b00100000
    #define Si_BIT6 0x40    // 0b01000000
    #define Si_BIT7 0x80    // 0b10000000

    #define No_BIT0 0xfe    // 0b11111110
    #define No_BIT1 0xfd    // 0b11111101
    #define No_BIT2 0xfb    // 0b11111011
    #define No_BIT3 0xf7    // 0b11110111
    #define No_BIT4 0xef    // 0b11101111
    #define No_BIT5 0xdf    // 0b11011111
    #define No_BIT6 0xbf    // 0b10111111
    #define No_BIT7 0x7f    // 0b01111111

    #define FLUJO_OUTPUT 0x03 // 00000011
    #define FLUJO_INPUT  0x3c // 00111100
    #define FLUJO_ERROR  0xc0 // 11000000
    #define CONSOLA_OUTPUT FLUJO_OUTPUT
    #define CONSOLA_INPUT  FLUJO_INPUT
    #define CONSOLA_ERROR  FLUJO_ERROR

    #define UTILIZAR_DEF_TIPOS_H  Si // <- cambiar

    // apartado de incluciones
    #include <stddef.h>
    #if UTILIZAR_DEF_TIPOS_H
        #include "DefTipos.h"
    #else
        #include <stdint.h>

        typedef int8_t   S8;
        typedef int16_t  S16;
        typedef int32_t  S32;
        typedef int64_t  S64;

        typedef uint8_t  U8;
        typedef uint16_t U16;
        typedef uint32_t U32;
        typedef uint64_t U64;
    #endif
#endif
