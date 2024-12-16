cmake_minimum_required(VERSION 3.31)

set(ella_headers 
    component.h 
    entity.h 
    engine.h 
    hash_table.h 
    renderer.h 
    system.h 
    window.h)

set(ella_sources 
    component.c 
    entity.c 
    engine.c 
    hash_table.c 
    renderer.c 
    system.c 
    window.c)

add_executable(ella main.c ${ella_headers} ${ella_sources})
target_link_libraries(ella PRIVATE glad glfw)