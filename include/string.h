/* Implementação de strings dinâmicas do REDIS */
#ifndef STRING_H
#define STRING_H
#include <my_ints.h>


typedef struct dynamic_strings {
    int64 len;  
    char *string;  
} dynamic_strings;

void insert();

#endif 