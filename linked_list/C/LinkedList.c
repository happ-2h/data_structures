#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList* LinkedList_new() {
  LinkedList* temp = malloc(sizeof(LinkedList));

  temp->head = NULL;

  temp->add = LinkedList_add;
  temp->print = LinkedList_print;
  temp->clear = LinkedList_clear;

  return temp;
}

void LinkedList_destroy(LinkedList* self) {
  if (self) {
    if (self->head)
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
  if (!self->head)return;

  Node* temp = self->head->next;

  while (temp) {
    free(self->head);
    self->head = temp;
    temp = temp->next;
  }
  if (self->head) {
    free(self->head);
    self->head = NULL;
  }
}