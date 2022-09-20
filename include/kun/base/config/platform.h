#pragma once

//-------------------------------------------------------------------------------
// -> platform
//      KUN_PLATFORM_LINUX
//
//      KUN_PLATFORM_WINDOWS
//      KUN_PLATFORM_WIN32
//      KUN_PLATFORM_WIN64
//
//      KUN_PLATFORM_APPLE
//      KUN_PLATFORM_IPHONE
//      KUN_PLATFORM_OSX
//
// -> abi
//
// -> cpu
//      KUN_PROCESSOR_X86
//      KUN_PROCESSOR_X86_64
//      KUN_PROCESSOR_ARM32
//      KUN_PROCESSOR_ARM64
//      KUN_PROCESSOR_POWERPC_32
//      KUN_PROCESSOR_POWERPC_64
//      KUN_PROCESSOR_IA64
//
// -> size
//
//-------------------------------------------------------------------------------

//platform def
#if defined(KUN_PLATFORM_LINUX) || (defined(__linux) || defined(__linux__))
    // platform
    #undef KUN_PLATFORM_LINUX
    #define KUN_PLATFORM_LINUX 1

    // processor
    #if defined(__i386__) || defined(__intel__) || defined(_M_IX86)
        #define KUN_PROCESSOR_X86 1
    #elif defined(__x86_64__)
        #define KUN_PROCESSOR_X86_64 1
    #elif defined(__ARM_ARCH_7A__) || defined(__ARM_EABI__)
        #define KUN_PROCESSOR_ARM32 1
    #elif defined(__aarch64__) || defined(__AARCH64)
        #define KUN_PROCESSOR_ARM64 1
    #elif defined(__powerpc__)
        #define KUN_PROCESSOR_POWERPC_32 1
    #elif defined(__powerpc64__)
        #define KUN_PROCESSOR_POWERPC_64 1
    #else
        #error Unknown processor
    #endif

// TODO. abi

#elif defined(KUN_PLATFORM_WINDOWS) || (defined(_WIN32) || defined(__WIN32__) || defined(_WIN64))
    // platform
    #undef KUN_PLATFORM_WINDOWS
    #define KUN_PLATFORM_WINDOWS 1
    #ifdef _WIN64
        #define KUN_PLATFORM_WIN64 1
    #else
        #define KUN_PLATFORM_WIN32 1
    #endif

    // processor
    #if defined(_M_IX86) || defined(_X86_)
        #define KUN_PROCESSOR_X86 1
    #elif defined(_M_AMD64) || defined(_AMD64_) || defined(__x86_64__)
        #define KUN_PROCESSOR_X86_64 1
    #elif defined(_M_ARM)
        #define KUN_PROCESSOR_ARM32 1
    #elif defined(_M_ARM64)
        #define KUN_PROCESSOR_ARM64 1
    #elif defined(_M_IA64) || defined(_IA64_)
        #define KUN_PROCESSOR_IA64 1
    #else
        #error Unknown processor
        #error Unknown endianness
    #endif

    // TODO. abi

#elif defined(KUN_PLATFORM_APPLE) || (defined(__APPLE__) && __APPLE__)
    // platform
    #undef KUN_PLATFORM_APPLE
    #define KUN_PLATFORM_APPLE 1
    #if defined(EA_PLATFORM_IPHONE) || defined(__IPHONE__) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || (defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR)
        #undef  KUN_PLATFORM_IPHONE
        #define KUN_PLATFORM_IPHONE 1
    #elif defined(EA_PLATFORM_OSX) || defined(__MACH__) || (defined(__MSL__) && (__dest_os == __mac_os_x))
        #undef  KUN_PLATFORM_OSX
        #define KUN_PLATFORM_OSX 1
    #else
        #error Unknown Apple Platform
    #endif

    // processor
    #if defined(EA_PLATFORM_IPHONE) || defined(__IPHONE__) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || (defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR)
        // iphone
        #if defined(__arm__)
            #define KUN_PROCESSOR_ARM32 1
        #elif defined(__aarch64__) || defined(__AARCH64)
            #define KUN_PROCESSOR_ARM64 1
        #elif defined(__i386__)
            #define KUN_PROCESSOR_X86 1
        #elif defined(__x86_64) || defined(__amd64)
            #define KUN_PROCESSOR_X86_64 1
        #else
            #error Unknown processor
        #endif
    #elif defined(EA_PLATFORM_OSX) || defined(__MACH__) || (defined(__MSL__) && (__dest_os == __mac_os_x))
        // osx
        #if defined(__i386__) || defined(__intel__)
            #define KUN_PROCESSOR_X86 1
        #elif defined(__x86_64) || defined(__amd64)
            #define KUN_PROCESSOR_X86_64 1
        #elif defined(__arm__)
            #define KUN_PROCESSOR_ARM32 1
        #elif defined(__aarch64__) || defined(__AARCH64)
            #define KUN_PROCESSOR_ARM64 1
        #elif defined(__POWERPC64__) || defined(__powerpc64__)
            #define KUN_PROCESSOR_POWERPC 1
            #define KUN_PROCESSOR_POWERPC_64 1
        #elif defined(__POWERPC__) || defined(__powerpc__)
            #define KUN_PROCESSOR_POWERPC 1
            #define KUN_PROCESSOR_POWERPC_32 1
        #else
            #error Unknown processor
        #endif
    #endif

    // TODO. abi

#endif