#include "parser.h"

void set_function(char **argv, int argc)
{
    if (argc < 3)
    {
        printf("Missing command.\n");
        return;
    }
    if (strcmp(argv[0], "SET") == 0)
    {
        char *key = argv[1];
        char *value = argv[2];
        dict_set(key, value);
        printf("Stored: %s -> %s! \n", key, value);
    }
}

void get_function(char **argv, int argc)
{
    if (argc < 2)
    {
        printf("Missing command.\n");
        return;
    }
    if (strcmp(argv[0], "GET") == 0)
    {
        char *key = argv[1];
        char *val = dict_find(key);
        printf("%s\n", val);
    }
}