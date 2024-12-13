#include "engine.h"

int main(int argc, char **argv) {
  engine_t *engine = engine_create();
  engine_run(engine);
  engine_destroy(engine);
  return 0;
}