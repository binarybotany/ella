#include "hash_table.h"

struct node_t {
  char *key;
  char *val;
  struct node_t *next;
};

struct hash_table_t {
  node_t *buckets[TABLE_SIZE];
};

unsigned int hash(const char *key) {
  unsigned int hash = 0;
  while (*key) {
    hash = (hash << 5) + *key++;
  }
  return hash % TABLE_SIZE;
}

hash_table_t *create_hash_table() {
  hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));
  for (int i = 0; i < TABLE_SIZE; ++i) {
    table->buckets[i] = NULL;
  }
  return table;
}

node_t *create_node(const char *key, const char *val) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->key = strdup(key);
  node->val = strdup(val);
  node->next = NULL;
  return node;
}

void hash_table_insert(hash_table_t *table, const char *key, const char *val) {
  unsigned int index = hash(key);
  node_t *node = create_node(key, val);

  if (table->buckets[index] == NULL) {
    table->buckets[index] = node;
    return;
  }

  node_t *temp = table->buckets[index];
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = node;
}

char *hash_table_search(hash_table_t *table, const char *key) {
  unsigned int index = hash(key);
  node_t *temp = table->buckets[index];
  while (temp) {
    if (strcmp(temp->key, key) == 0) {
      return temp->val;
    }
    temp = temp->next;
  }
  return NULL;
}

void hash_table_remove(hash_table_t *table, const char *key) {
  unsigned int index = hash(key);
  node_t *temp = table->buckets[index];
  node_t *prev = NULL;

  while (temp) {
    if (strcmp(temp->key, key) == 0) {
      if (prev) {
        prev->next = temp->next;
      } else {
        table->buckets[index] = temp->next;
      }

      free(temp->key);
      free(temp->val);
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
}

void destroy_hash_table(hash_table_t *table) {
  for (int i = 0; i < TABLE_SIZE; ++i) {
    node_t *temp = table->buckets[i];
    while (temp) {
      node_t *next = temp->next;
      free(temp->key);
      free(temp->val);
      free(temp);
      temp = next;
    }
  }
  free(table);
}