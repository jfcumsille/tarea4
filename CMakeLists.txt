cmake_minimum_required(VERSION 3.8)
project(T4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/chess/main.c src/lib/functions.c src/lib/functions.h)

add_executable(T4 ${SOURCE_FILES})