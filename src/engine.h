#ifndef ELLA_ENGINE_H_
#define ELLA_ENGINE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "renderer.h"
#include "window.h"

typedef struct engine_t engine_t;

engine_t *engine_create();
void engine_run(engine_t *engine);
void engine_update(engine_t *engine);
void engine_render(engine_t *engine);
void engine_destroy(engine_t *engine);

#endif