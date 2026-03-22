#include "list.h"

list *create_list(void)
{
    list *new_list = malloc(sizeof(list));
    if (!new_list)
    {

        return NULL;
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->len = 0;
    return new_list;
}
list *initialize_list(void *value)
{
    list *new_list = create_list();
    if (!new_list)
    {
        return NULL;
    }
    node_list *new_node = malloc(sizeof(node_list));
    if (!new_node)
    {
        free(new_list);
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_list->head = new_node;
    new_list->tail = new_node;
    new_list->len = 1;
    return new_list;
}
uint64 get_list_length(list *list)
{
    return list->len;
}
void empty_list(list *list)
{
    node_list *curr_node = list->head;
    node_list *next_node;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}
void list_release(list *list)
{
    if (!list)
    {
        return;
    }
    empty_list(list);
    free(list);
}
void push_back(list *list, void *value)
{
    node_list *new_tail = malloc(sizeof(node_list));
    if (new_tail == NULL)
    {
        return;
    }
    new_tail->value = value;
    new_tail->prev = list->tail;
    new_tail->next = NULL;
    if (list->tail)
    {
        list->tail->next = new_tail;
    }
    else
    {
        list->head = new_tail;
    }
    list->tail = new_tail;
    list->len++;
}
void push_front(list *list, void *value)
{
    node_list *new_head = malloc(sizeof(node_list));
    if (new_head == NULL)
    {
        return;
    }
    new_head->value = value;
    new_head->next = list->head;
    new_head->prev = NULL;
    if (list->head)
    {
        list->head->prev = new_head;
    }
    else
    {
        list->tail = new_head;
    }
    list->head = new_head;
    list->len++;
}
void pop_front(list *list)
{
    if (list == NULL || list->head == NULL)
    {
        return;
    }
    node_list *temp = list->head;
    if (list->head->next == NULL)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = temp->next;
        list->head->prev = NULL;
    }
    free(temp);
    list->len--;
}
void pop_back(list *list)
{
    if (list == NULL || list->tail == NULL)
    {
        return;
    }
    node_list *temp = list->tail;
    if (list->tail->prev == NULL)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = temp->prev;
        list->tail->next = NULL;
    }
    free(temp);
    list->len--;
}
void remove_list_index(list *list, uint64 index)
{
    if (list == NULL || index >= list->len)
    {
        return;
    }
    node_list *curr = list->head;
    for (int i = 0; i < index; i++){
        curr = curr->next;
    }
    if (curr->prev)
    {
        curr->prev->next = curr->next;
    }
    else
    {
        list->head = curr->next;
    }
    if (curr->next)
    {
        curr->next->prev = curr->prev;
    }
    else
    {
        list->tail = curr->prev;
    }
    free(curr);
    list->len--;
}