#ifndef LIST_H
#define LIST_H
#include <my_ints.h>


typedef struct node_list {
    struct node_list *next;
    struct node_list *prev;
    void *value;
} node_list;




#endif 