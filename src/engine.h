#ifndef ELLA_ENGINE_H_
#define ELLA_ENGINE_H_

#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "window.h"

typedef struct engine_t engine_t;

engine_t *engine_create();
void engine_run(engine_t *engine);
void engine_update();
void engine_render();
void engine_destroy(engine_t *engine);

#endif