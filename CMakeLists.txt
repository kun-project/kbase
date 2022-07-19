cmake_minimum_required(VERSION 3.16.0)

# fix warning in clang-cl
message(STATUS "use compiler: ${CMAKE_C_COMPILER}")
message(STATUS "c flags: ${CMAKE_C_FLAGS}")

# project 
project(kun VERSION 0.0.0 LANGUAGES CXX)

# config cpp
set(CMAKE_CXX_STANDARD 17)

# config msvc 
if (WIN32)
    # shit msvc
    add_compile_definitions(NOMINMAX)

    # enable __cplusplus marco
    add_definitions(/Zc:__cplusplus)

    # enable exception handling
    if (DEFINED CMAKE_C_COMPILER)
        add_definitions(/GX)
    endif ()
endif()

# force x64
if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(SEND_ERROR "only support x64 build")
    return()
endif ()

# options

# src code
add_subdirectory(src/core)

# test code
if (KUN_WITH_TEST)
    # enable test
    enable_testing()

    # find gtest lib
    find_package(GTest REQUIRED)

    # add test targets
    add_subdirectory(tests/test_core)
endif ()