#ifndef DICT_H
#define DICT_H
#include <stdint.h>
#include <stdlib.h>
#include <my_ints.h>
#define DICT_VALID 0
#define DICT_INVALID 1
#define TABLE_SIZE 101

typedef struct dict_entry
{
    char *key;
    char *value;
    struct dict_entry *next;
} dict_entry;

typedef struct dict_hash_table
{
    dict_entry **table;
    uint64 size;
    uint64 size_mask;
    uint64 used;
} dict_hash_table;

typedef struct dict
{
    dict_hash_table dict_hash[2];
    int32 rehashing;
} dict;


dict *dict_create(void);
int dict_add(dict *d, char *key, char *value);
dict_entry *dict_find(dict *d, const char *key);
dict_entry *
#endif