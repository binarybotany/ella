#ifndef ELLA_RENDERER_H_
#define ELLA_RENDERER_H_

#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>

#include "component.h"

typedef struct renderer_t renderer_t;

renderer_t *renderer_create();
void renderer_destroy(void *renderer);
void renderer_system(renderer_t *renderer);
#endif