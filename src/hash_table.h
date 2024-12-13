#ifndef ELLA_HASH_TABLE_H_
#define ELLA_HASH_TABLE_H_

#define TABLE_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t node_t;
typedef struct hash_table_t hash_table_t;

unsigned int hash(const char *key);
hash_table_t *create_hash_table();
node_t *create_node(const char *key, const char *val);
void hash_table_insert(hash_table_t *table, const char *key, const char *val);
char *hash_table_search(hash_table_t *table, const char *key);
void hash_table_remove(hash_table_t *table, const char *key);
void destroy_hash_table(hash_table_t *table);

#endif