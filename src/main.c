#include "component.h"
#include "engine.h"
#include "entity.h"
#include "system.h"

int main(int argc, char **argv) {
  entity_t player = entity_create();
  entity_t monster = entity_create();

  component_startup();

  transform_add(player, 0.0f, 0.0f, 0.0f);
  transform_add(monster, 5.0f, 5.0f, 0.0f);

  for (size_t i = 0; i < 10; ++i) {
    system_physics();
  }

  component_shutdown();

  engine_t *engine = engine_create();
  engine_run(engine);
  engine_destroy(engine);
  return 0;
}