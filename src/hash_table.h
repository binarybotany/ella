#ifndef ELLA_HASH_TABLE_H_
#define ELLA_HASH_TABLE_H_

#define INITIAL_TABLE_SIZE 8
#define LOAD_FACTOR_THRESHOLD 0.5

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t node_t;
typedef struct hash_table_t hash_table_t;

hash_table_t *ht_create(size_t size);
bool ht_insert(hash_table_t *table, const char *key, void *val);
void *ht_search(hash_table_t *table, const char *key);
void ht_delete(hash_table_t *table, const char *key);
void ht_destroy(hash_table_t *table);

#endif