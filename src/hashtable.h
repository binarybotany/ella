#ifndef ELLA_hashtable_H_
#define ELLA_hashtable_H_

#define INITIAL_TABLE_SIZE 8
#define LOAD_FACTOR_THRESHOLD 0.5

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t node_t;
typedef struct hashtable_t hashtable_t;

hashtable_t *ht_create(size_t size);
bool ht_insert(hashtable_t *table, const char *key, void *val,
               void (*destructor)(void *));
void *ht_search(hashtable_t *table, const char *key);
void ht_delete(hashtable_t *table, const char *key);
void ht_destroy(hashtable_t *table);

#endif