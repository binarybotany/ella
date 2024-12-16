#include "entity.h"

entity_t entity_create() {
  static entity_t next = 0;
  return next++;
}