#include "engine.h"

struct engine_t {
  bool running;
  hashtable_t *state;
};

engine_t *engine_create() {
  engine_t *engine = (engine_t *)malloc(sizeof(engine_t));
  if (!engine) {
    fprintf(stderr, "Unable to allocate memory to initialize engine\n");
    return NULL;
  }
  engine->running = true;
  engine->state = ht_create(16);
  window_t *window = window_create();
  renderer_t *renderer = renderer_create();
  ht_insert(engine->state, "window", window, &window_destroy);
  ht_insert(engine->state, "renderer", renderer, &renderer_destroy);
  return engine;
}

void engine_run(engine_t *engine) {
  window_t *window = (window_t *)ht_search(engine->state, "window");
  if (!window) {
    fprintf(stderr, "Unable to retrieve window from engine state\n");
    return;
  }
  window_loop(window, &engine_update, &engine_render, engine);
}

void engine_update(engine_t *engine) {
  renderer_t *renderer = (renderer_t *)ht_search(engine->state, "renderer");
  renderer_update(renderer);
}

void engine_render(engine_t *engine) {
  renderer_t *renderer = (renderer_t *)ht_search(engine->state, "renderer");
  renderer_render(renderer);
}

void engine_destroy(engine_t *engine) {
  ht_destroy(engine->state);
  free(engine);
}