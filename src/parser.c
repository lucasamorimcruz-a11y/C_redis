#include "parser.h"
/*
    TO DO -> iMPLEMENTAR UMA FORMA DE DISPATCH TABLE COM TABELA DE PONTEIROS.
*/

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
        /*
            TO DO -> adicionar a lógica do server / armazenamento.
        */
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
        /*
           TO DO -> adicionar a lógica do server / armazenamento.
       */
        printf("%s\n", val);
    }
}
void keys_function(char **argv, int argc)
{
    if (argc < 2)
    {
        printf("Missing command.\n");
        return;
    }
    if (strcmp(argv[0], "KEYS") == 0)
    {
        char *pattern = argv[1];
        char **keys = find_pattern(pattern);
        int index = 0;
        /*
           TO DO -> adicionar a lógica do server / armazenamento.
       */
        while (strcmp (keys[index], "\0") != 0)
        {
            printf("%s\n", keys[index]);
            index++;
        }
    }
}
void exists_function(char **argv, int argc)
{
    if (argc < 2)
    {
        printf("Missing command.\n");
        return;
    }
    if (strcmp(argv[0], "EXISTS") == 0)
    {
        for (int index = 1; index < argc; index++)
        {
            if (!(dict_find(argv[index])))
            {
                printf("Couldn't find %s\n", argv[index]);
            }
            else{
                printf("1");
            }
        }
    }
    /*
           TO DO -> adicionar a lógica do server / armazenamento.
   */
}

void del_function(char **argv, int argc)
{
    if (argc < 2)
    {
        printf("Missing command.\n");
        return;
    }
    if (strcmp(argv[0], "DEL") == 0)
    {
        for (int index = 1; index < argc; index++)
        {
            dict_delete(argv[index]);
        }
        /*
        TO DO -> adicionar a lógica do server / armazenamento.
        */
    }
}
