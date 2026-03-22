#ifndef LIST_H
#define LIST_H
#include <my_ints.h>
#include <stddef.h>
#include <stdio.h>

typedef struct node_list
{
    struct node_list *next;
    struct node_list *prev;
    void *value;
} node_list;

typedef struct list
{
    struct node_list *head;
    struct node_list *tail;
    uint64 len;
} list;

list *create_list (void);
list *initialize_list(void *list);
uint64 get_list_length(list *list);
void empty_list(list *list);
void list_release(list *list);
void push_front(list *list, void *value);
void push_back(list *list, void *value);
void pop_front(list *list);
void pop_back (list *list);
void remove_list_index (list *list, uint64 index);

#endif