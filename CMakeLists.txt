cmake_minimum_required(VERSION 3.16.0)

# setup vcpkg
if (DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "")
    message(STATUS "using vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}:${VCPKG_TARGET_TRIPLET}")
else ()
    message(SEND_ERROR "lost vcpkg toolchain please set 'VCPKG_ROOT' env value")
endif ()

# fix warning
message(STATUS "use compiler: ${CMAKE_C_COMPILER}")
message(STATUS "c flags: ${CMAKE_C_FLAGS}")

# proj
project(kbase VERSION 0.0.0 LANGUAGES CXX)

# config cpp
set(CMAKE_CXX_STANDARD 17)

# enable __cplusplus marco
if (WIN32)
    add_definitions(/Zc:__cplusplus)
endif ()

# options
option(KUN_WITH_TEST "enable test for kun project" ON)

# add target
add_library(kbase INTERFACE)

# add include
target_include_directories(kbase INTERFACE include)

# install
install(DIRECTORY include/kun DESTINATION include)

# test code
if (KUN_WITH_TEST)
    # enable test
    enable_testing()

    # find gtest lib
    find_package(GTest REQUIRED)

    # add test targets
    add_subdirectory(tests)
endif ()