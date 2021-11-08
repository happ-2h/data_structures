#include "Tree.h"

int main(int argc, char const *argv[]) {
  Tree tree;

  for (int i = 0; i < 10; ++i) {
    tree.insert(i);
  }

  tree.print_inorder();
  
  return 0;
}
