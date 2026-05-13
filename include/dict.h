#ifndef DICT_H
#define DICT_H
#include <stdint.h>
#include <stdlib.h>
#include <my_ints.h>
#define DICT_VALID 0
#define DICT_INVALID 1

typedef struct {
    char *key;
} Item;

void dict_set (char *key, char *val);
int dict_find (char *key);
void dict_delete (char *key);
void find_pattern(char *pattern);


#endif