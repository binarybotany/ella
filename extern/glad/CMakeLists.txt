cmake_minimum_required(VERSION 3.31)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(glad LANGUAGES C)

add_library(glad src/glad.c include/glad/glad.h)
target_include_directories(glad PUBLIC include)