#include <my_ints.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dict.h"

typedef void (*command_fn)(char **argv, int argc);

void set_function(char **argv, int argc);
void get_function(char **argv, int argc);
 // while -> dict_find.

int main (){
    int choice = 1;
    command_fn table[3] = {
        set_function,
        get_function,
    };
    char *argv []= {"ola", "caguei"};
    int argc = 2;
    table[choice] (argv,argc); 
}

