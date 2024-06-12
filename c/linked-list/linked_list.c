#include "linked_list.h"

// not passing yet, segmentation fault (very fun)

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create()
{
   struct list *new = malloc(sizeof(struct list));
   if (new == NULL)
      return NULL;

   new->first = NULL;
   new->last = NULL;
   return new;
}

size_t list_count(const struct list *list)
{
   size_t count = 0;
   struct list_node *current = list->first;
   while (current != NULL)
   {
      count++;
      current = current->next;
   }
   return count;
}

void list_push(struct list *list, ll_data_t item_data)
{
   struct list_node *new = (struct list_node *)malloc(sizeof(struct list_node));
   if (new == NULL)
      return;

   new->data = item_data;
   new->next = NULL;

   if (list->last == NULL)
   {
      new->prev = NULL;
      list->first = new;
      list->last = new;
   }
   else
   {
      new->prev = list->last;
      list->last->next = new;
      list->last = new;
   }
}

ll_data_t list_pop(struct list *list)
{
   ll_data_t data = list->last->data;
   struct list_node *temp = list->last;
   list->last = list->last->prev;
   if (list->last == NULL)
   {
      list->first = NULL;
   }
   else
   {
      list->last->next = NULL;
   }
   free(temp);
   return data;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   struct list_node *new = malloc(sizeof(struct list_node));
   if (new == NULL)
      return;
   
   new->data = item_data;
   new->next = list->first;
   list->first = new;
}

ll_data_t list_shift(struct list *list)
{
   ll_data_t data = list->first->data;
   struct list_node *temp = list->first;
   list->first = list->first->next;
   if (list->first == NULL)
   {
      list->last = NULL;
   }
   else
   {
      list->first->prev = NULL;
   }
   free(temp);
   return data;
}

void list_delete(struct list *list, ll_data_t data)
{
   struct list_node *current = list->first;
   while (current != NULL)
   {
      if (current->data == data)
      {
         if (current == list->first)
         {
            list->first = list->first->next;
         }
         else if (current == list->last)
         {
            list->last = list->last->prev;
         }
         else
         {
            current->prev->next = current->next;
            current->next->prev = current->prev;
         }
         free(current);
         break;
      }
      current = current->next;
   }
}

void list_destroy(struct list *list)
{
   struct list_node *current = list->first;
   struct list_node *temp;
   while (current != NULL)
   {
      temp = current->next;
      free(current);
      current = temp;
   }
   free(list);
}