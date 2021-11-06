#include "LinkedList.h"

int main(int argc, char const *argv[]) {
  LinkedList* list = LinkedList_new();

  for (int i = 0; i < 10; ++i) {
    list->add(list, i);
  }
  
  list->print(list);

  LinkedList_destroy(list);

  return 0;
}
