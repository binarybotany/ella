#ifndef ELLA_WINDOW_H_
#define ELLA_WINDOW_H_

#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct window_t window_t;

window_t *window_create();
void window_loop(window_t *window, void (*update)(), void (*render)(),
                 void *context);
void window_destroy(void *window);

#endif