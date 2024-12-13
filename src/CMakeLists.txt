cmake_minimum_required(VERSION 3.31)

set(ella_headers hash_table.h)
set(ella_sources hash_table.c)

add_executable(ella main.c ${ella_headers} ${ella_sources})
target_link_libraries(ella PRIVATE glad glfw)