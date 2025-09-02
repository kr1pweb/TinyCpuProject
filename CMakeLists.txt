cmake_minimum_required(VERSION 3.10)
project(TinyCpuProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/releases)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
    src/main.cpp
    src/TinyCpu/TinyCpu.cpp
    src/TinyCpu/TinyCpu.hpp
    src/Assembler/Assembler.cpp
    src/Assembler/OpCodes/OpCodes.cpp
    src/Assembler/OpCodes/OpCodes.h
)

include_directories(
    src
    src/TinyCpu
    src/Assembler
    src/Assembler/OpCodes
)

add_executable(main ${SOURCES})