#ifndef ELLA_ENTITY_H_
#define ELLA_ENTITY_H_

#include <stdint.h>

typedef uint32_t entity_t;

entity_t entity_create() {
  static entity_t next = 0;
  return next++;
}

#endif