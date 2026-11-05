// GeneralDef.h
#ifndef GNRAL_DEF_H 
    #define GNRAL_DEF_H "V: 1.4 | NumHeader: 3"

    #define WINDOWS_32BIT 0x10
    #define WINDOWS_64BIT 0x20
    #define WINDOWS_GNRAL 0x40
    #define LINUX         0xb0

    #define _SING_AND_MAGNITUDE_ 0x01
    #define _ONE_COMPLEMENT_     0x02
    #define _TWO_COMPLEMENT_     0x03

    #if defined(_WIN64)
        #define Operating_System WINDOWS_64BIT
    #elif defined(_WIN32)
        #define Operating_System WINDOWS_32BIT
    #elif defined(__linux__)
        #define Operating_System LINUX
    #else
        #error "Unknown Environment (only WINDOWS)"
    #endif

    #define True   0x01  
    #define False  0x00  

    #define Yes True  
    #define No  False  

    typedef signed   int  Sint_t;
    typedef unsigned int  Uint_t;
    typedef unsigned char Byte_t;
    typedef unsigned char Bool_t;
    typedef unsigned char BoolBit_t;

    #define Yes_BIT0 (0b00000001)
    #define Yes_BIT1 (0b00000010)
    #define Yes_BIT2 (0b00000100)
    #define Yes_BIT3 (0b00001000)
    #define Yes_BIT4 (0b00010000)
    #define Yes_BIT5 (0b00100000)
    #define Yes_BIT6 (0b01000000)
    #define Yes_BIT7 (0b10000000)

    #define No_BIT0 (~(0b00000001))
    #define No_BIT1 (~(0b00000010))
    #define No_BIT2 (~(0b00000100))
    #define No_BIT3 (~(0b00001000))
    #define No_BIT4 (~(0b00010000))
    #define No_BIT5 (~(0b00100000))
    #define No_BIT6 (~(0b01000000))
    #define No_BIT7 (~(0b10000000))

    #define FLOW_OUTPUT 0x03 // 00000011
    #define FLOW_INPUT  0x3c // 00111100
    #define FLOW_ERROR  0xc0 // 11000000
    #define CONSOLE_OUTPUT FLOW_OUTPUT
    #define CONSOLE_INPUT  FLOW_INPUT
    #define CONSOLE_ERROR  FLOW_ERROR

    #define USE_TYPES_DEF_H  Yes // <- change

    #if USE_TYPES_DEF_H
        #include "TypesDef.h"
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