cmake_minimum_required(VERSION 3.31)

add_executable(ella main.c)
target_link_libraries(ella PRIVATE glad glfw)