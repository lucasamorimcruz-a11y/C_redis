#ifndef DICT_H
#define DICT_H
#include <stdint.h>
#include <stdlib.h>
#include <my_ints.h>
#define DICT_VALID 0
#define DICT_INVALID 1



typedef struct  {
    int key;
    char * info;
} Item;     

void dict_set (char *key, char *val);
void dict_find (char *key);



#endif