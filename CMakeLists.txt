cmake_minimum_required(VERSION 3.31)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(ella LANGUAGES C)

add_subdirectory(src bin)