cmake_minimum_required(VERSION 3.31)

set(ella_headers engine.h hash_table.h window.h)
set(ella_sources engine.c hash_table.c window.c)

add_executable(ella main.c ${ella_headers} ${ella_sources})
target_link_libraries(ella PRIVATE glad glfw)