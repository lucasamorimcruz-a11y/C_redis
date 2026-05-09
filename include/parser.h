#include <my_ints.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dict.h"

typedef struct {
    char *name;
    void ( *handler) (char **argv, int argc);
} command_t; // EX

void set_function(char **argv, int argc);
void get_function(char **argv, int argc);
void find_pattern(char *pattern); // while -> dict_find.