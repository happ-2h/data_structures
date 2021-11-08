#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

typedef struct LINKEDLIST {
  // Private
  Node* head;

  void (*add)(struct LINKEDLIST*, int);
  void (*print)(struct LINKEDLIST*);
  void (*clear)(struct LINKEDLIST*);
} LinkedList;

LinkedList* LinkedList_new();
void LinkedList_destroy(LinkedList*);

void LinkedList_add(LinkedList* self, int data);
void LinkedList_print(LinkedList* self);
void LinkedList_clear(LinkedList* self);

#endif