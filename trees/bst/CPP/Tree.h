#pragma once

#include "Node.h"

class Tree {
  private:
    Node* m_root{nullptr};

    void p_insert(Node*, int);
    void p_inorder(Node*);
    void p_clear(Node*);

  public:
    Tree() = default;
    Tree(int);

    ~Tree();

    void insert(int);
    void print_inorder();
    void clear();
};