#include "component.h"

transform_entry_t *transforms = NULL;
size_t ntransforms = 0;

void transform_add(entity_t entity, transform_t transform) {
  transform_entry_t entry = {entity, transform};
  transforms =
      realloc(transforms, sizeof(transform_entry_t) * (ntransforms + 1));
  transforms[ntransforms] = entry;
  ntransforms++;
}