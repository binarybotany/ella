#include "engine.h"

struct engine_t {
  hash_table_t *state;
};

engine_t *engine_create() {
  engine_t *engine = (engine_t *)malloc(sizeof(engine_t));
  if (!engine) {
    fprintf(stderr, "Unable to allocate memory to initialize engine\n");
    return NULL;
  }
  engine->state = ht_create(16);
  window_t *window = window_create();
  ht_insert(engine->state, "window", window, &window_destroy);
  return engine;
}

void engine_run(engine_t *engine) {
  window_t *window = (window_t *)ht_search(engine->state, "window");
  if (!window) {
    fprintf(stderr, "Unable to retrieve window from engine state\n");
    return;
  }
  window_loop(window, &engine_update, &engine_render);
}

void engine_update() { glClearColor(0.1f, 0.1f, 0.1f, 1.0f); }

void engine_render() { glClear(GL_COLOR_BUFFER_BIT); }

void engine_destroy(engine_t *engine) {
  ht_destroy(engine->state);
  free(engine);
}