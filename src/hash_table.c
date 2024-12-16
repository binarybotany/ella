#include "hash_table.h"

/* TODO: Add destructor to node */

struct node_t {
  char *key;
  void *val;
  void (*destructor)(void *);
  struct node_t *next;
};

struct hash_table_t {
  size_t size, count;
  node_t **buckets;
};

size_t ht_hash(const char *key, size_t size) {
  size_t hash = 0;
  while (*key) {
    hash = (hash << 5) ^ (hash >> 27) ^ *key++;
  }
  return hash % size;
}

hash_table_t *ht_create(size_t size) {
  hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));
  if (table == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    return NULL;
  }
  table->size = size;
  table->count = 0;
  table->buckets = (node_t **)malloc(sizeof(node_t *) * size);
  if (table->buckets == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    return NULL;
  }
  for (size_t i = 0; i < size; ++i) {
    table->buckets[i] = NULL;
  }
  return table;
}

node_t *ht_create_node(const char *key, void *val, void (*destructor)(void *)) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  if (node == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    return NULL;
  }
  node->key = strdup(key);
  node->val = val;
  node->destructor = destructor;
  node->next = NULL;
  return node;
}

void ht_rehash_all_elements(hash_table_t *table, node_t **new_buckets,
                            size_t new_size) {
  for (size_t i = 0; i < table->size; ++i) {
    node_t *node = table->buckets[i];
    while (node) {
      node_t *next = node->next;
      size_t index = ht_hash(node->key, new_size);

      node->next = new_buckets[index];
      new_buckets[index] = node;

      node = next;
    }
  }
}

bool ht_resize(hash_table_t *table) {
  size_t new_size = table->size * 2;
  node_t **new_buckets = (node_t **)malloc(sizeof(node_t *) * new_size);
  if (new_buckets == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    return false;
  }
  if (new_buckets == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    return false;
  }

  for (size_t i = 0; i < new_size; ++i) {
    new_buckets[i] = NULL;
  }

  ht_rehash_all_elements(table, new_buckets, new_size);

  free(table->buckets);
  table->buckets = new_buckets;
  table->size = new_size;

  return true;
}

bool ht_insert(hash_table_t *table, const char *key, void *val,
               void (*destructor)(void *)) {
  if ((float)table->count / table->size > LOAD_FACTOR_THRESHOLD) {
    if (!ht_resize(table)) {
      return false;
    }
  }

  size_t index = ht_hash(key, table->size);
  node_t *new_node = ht_create_node(key, val, destructor);
  new_node->next = table->buckets[index];
  table->buckets[index] = new_node;
  table->count++;

  return true;
}

void *ht_search(hash_table_t *table, const char *key) {
  size_t index = ht_hash(key, table->size);
  node_t *node = table->buckets[index];
  while (node) {
    if (strcmp(node->key, key) == 0) {
      return node->val;
    }
    node = node->next;
  }
  return NULL;
}

void ht_delete_node(node_t *node) {
  free(node->key);
  if (node->destructor) {
    node->destructor(node->val);
  }
  free(node);
}

void ht_delete(hash_table_t *table, const char *key) {
  size_t index = ht_hash(key, table->size);
  node_t *temp = table->buckets[index];
  node_t *prev = NULL;

  while (temp) {
    if (strcmp(temp->key, key) == 0) {
      if (prev) {
        prev->next = temp->next;
      } else {
        table->buckets[index] = temp->next;
      }
      ht_delete_node(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
}

void ht_destroy(hash_table_t *table) {
  for (size_t i = 0; i < table->size; ++i) {
    node_t *temp = table->buckets[i];
    while (temp) {
      node_t *next = temp->next;
      ht_delete_node(temp);
      temp = next;
    }
  }
  free(table->buckets);
  free(table);
}