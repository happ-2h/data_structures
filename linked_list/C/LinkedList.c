#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList* LinkedList_new(int data) {
  LinkedList* temp = malloc(sizeof(LinkedList));

  temp->head = NULL;

  temp->add = LinkedList_add;
  temp->print = LinkedList_print;

  return temp;
}

/*LinkedList* LinkedList_new(int data) {
  LinkedList* temp = malloc(sizeof(LinkedList));

  temp->head = malloc(sizeof(Node));
  temp->head->data = data;
  temp->head->next = NULL;

  temp->add = LinkedList_add;
  temp->print = LinkedList_print;

  return temp;
}*/

void LinkedList_destroy(LinkedList* self) {
  if (self) {
    self->clear(self);
    free(self);
    self = NULL;
  }
}

void LinkedList_add(LinkedList* self, int data) {
  if (!self->head) {
    self->head = malloc(sizeof(Node));
    self->head->data = data;
    self->head->next = NULL;
  }
  else {
    Node* temp = self->head;

    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    while (temp->next) {
      temp=temp->next;
    }
    temp->next=new_node;
  }
}

void LinkedList_print(LinkedList* self) {
  if (self->head) {
    Node* temp = self->head;

    while (temp) {
      printf("%d->", temp->data);
      temp=temp->next;
    }
  }
  printf("NULL\n");
}

void LinkedList_clear(LinkedList* self) {
  if (self->head) {
    Node* next = self->head;

    while(self->head) {
      next=next->next;
      free(self->head);
      self->head=next;
    }
  }
}