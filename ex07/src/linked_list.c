#include "linked_list.h"

node_t  *list_create(void *data)
{
  node_t  *list;

  list = (node_t *)malloc(sizeof(node_t));
  list->data = (void *)malloc(sizeof(data));
  list->data = data;
  list->next = NULL;
  return (list);
}

void    list_destroy(node_t **head, void (*fp)(void *data))
{
  node_t  *next;

  while (*head)
  {
    next = (*head)->next;
    (*fp)((*head)->data);
    free(*head);
    *head = NULL;
    *head = next;
  }
}

void    list_push(node_t *head, void *data)
{
  node_t  *next;

  while ((head->next))
    head = head->next;
  head->next = list_create(data);
}

void    list_unshift(node_t **head, void *data)
{
  node_t *new_head;

  new_head = list_create(data);
  new_head->next = *head;
  *head = new_head;
}

void    *list_pop(node_t **head)
{
  node_t   *list;
  void      *res;

  list = *head;
  while (list->next->next)
    list = list->next;
  res = list->next->data;
  free(list->next->data);
  free(list->next);
  list->next = NULL;
  return (res);
}

void    *list_shift(node_t **head)
{
  node_t  *list;

  list = (*head)->next;
  free((*head)->data);
  free(*head);
  *head = list;
}

void    *list_remove(node_t **head, int pos)
{
  int i;

  i = 0;
  while (i++ < pos)
    list_shift(head);
}

void    list_print(node_t *head)
{
  while (head->next)
  {
    printf(head->data);
    head = head->next;
  }
}

void    list_visitor(node_t *head, void (*fp)(void *data))
{
  while (head->next)
  {
    fp(head->data);
    head = head->next;
  }
}