// TypesDef.h
#ifndef TYPES_DEF_H
    #define TYPES_DEF_H "V: 2.1 | NumH: 6"

    #define NO_64BIT 0
    #define BOTH_64BIT 1
    #define ONLY_UNSIGNED_64BIT 2
    #define ONLY_SIGNED_64BIT 3
    /*                                  -\ 
    |  @attention: This header does not  |
    |  guarantee safety or consistency   |
    |  across implementations.           |
    \-                                  */ 

    #if defined(__GNUC__) || defined(__clang__)

        #if __CHAR_BIT__ == 8
            // Signed
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __INT8_TYPE__
                typedef __INT8_TYPE__ S8;
            #else
                #error "'__INT8_TYPE__' is not defined"
            #endif

            #ifdef __INT16_TYPE__
                typedef __INT16_TYPE__ S16;
            #else
                #error "'__INT16_TYPE__' is not defined"
            #endif

            #ifdef __INT32_TYPE__
                typedef __INT32_TYPE__ S32;
            #else
                #error "'__INT32_TYPE__' is not defined"
            #endif

            #ifdef __INT64_TYPE__
                typedef __INT64_TYPE__ S64;
            #else
                #warning "'__INT64_TYPE__' is not defined by the compiler. This is not an error"
            #endif
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII


            // Unsigned
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __UINT8_TYPE__
                typedef __UINT8_TYPE__ U8;
            #else
                #error "'__UINT8_TYPE__' is not defined"
            #endif

            #ifdef __UINT16_TYPE__
                typedef __UINT16_TYPE__ U16;
            #else
                #error "'__UINT16_TYPE__' is not defined"
            #endif

            #ifdef __UINT32_TYPE__
                typedef __UINT32_TYPE__ U32;
            #else
                #error "'__UINT32_TYPE__' is not defined"
            #endif

            #ifdef __SIZE_TYPE__
                typedef __SIZE_TYPE__ size_t;
            #else
                #error "'__SIZE_TYPE__' is not defined"
            #endif

            #ifdef __UINT64_TYPE__
                typedef __UINT64_TYPE__ U64;
            #else
                #warning "'__UINT64_TYPE__' is not defined by the compiler. This is not an error"
            #endif

            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII

            #if defined(__INT64_TYPE__) && defined(__UINT64_TYPE__)
                #define IS_64BIT_AVAILABLE BOTH_64BIT
            #elif defined(__INT64_TYPE__) && !(defined(__UINT64_TYPE__))
                #define IS_64BIT_AVAILABLE ONLY_SIGNED_64BIT
            #elif !(defined(__INT64_TYPE__)) && defined(__UINT64_TYPE__)
                #define IS_64BIT_AVAILABLE ONLY_UNSIGNED_64BIT
            #else
                #define IS_64BIT_AVAILABLE NO_64BIT
            #endif
        #else
            #error "'__CHAR_BIT__' is not 8 bits"
        #endif
    #elif defined(_MSC_VER)
        // TODO: IMPLEMENT MSVC SUPPORT
    #else
        #error "Compiler not supported"
    #endif
#endif
