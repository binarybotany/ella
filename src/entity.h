#ifndef ELLA_ENTITY_H_
#define ELLA_ENTITY_H_

#include <stdint.h>

#define MAX_ENTITIES 1024

typedef uint32_t entity_t;

entity_t entity_create();

#endif