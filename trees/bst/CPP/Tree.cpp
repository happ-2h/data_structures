#include <iostream>

#include "Tree.h"

Tree::Tree(int data) {
  m_root = new Node;
  m_root->data = data;
  m_root->left  = nullptr;
  m_root->right = nullptr;
}

Tree::~Tree() {
  p_clear(m_root);
}

void Tree::insert(int data=0) {
  if (!m_root) {
    m_root = new Node;
    m_root->data = data;
    m_root->left  = nullptr;
    m_root->right = nullptr;
  }
  else {
    if (data > m_root->data)
      if (m_root->right)
        p_insert(m_root->right, data);
      else {
        m_root->right = new Node;
        m_root->right->data = data;
        m_root->right->right = nullptr;
        m_root->right->left = nullptr;
      }
    else {
      if (m_root->left)
        p_insert(m_root->left, data); 
      else {
        m_root->left = new Node;
        m_root->left->data = data;
        m_root->left->right = nullptr;
        m_root->left->left = nullptr;
      }

    }
  }
}

void Tree::p_insert(Node* node, int data=0) {
  if (data > node->data) {
    if (node->right)
      p_insert(node->right, data);
    else {
      node->right = new Node;
      node->right->data = data;
      node->right->right = nullptr;
      node->right->left = nullptr;
    }
  }
  else {
    if (node->left)
      p_insert(node->left, data);
    else {
      node->left = new Node;
      node->left->data = data;
      node->left->right = nullptr;
      node->left->left = nullptr;
    }
  }
}

void Tree::print_inorder() {
  p_inorder(m_root);
}

void Tree::p_inorder(Node* node) {
  if (!node) return;

  p_inorder(node->left);
  std::cout << node->data << " ";
  p_inorder(node->right);
}

void Tree::clear() {
  p_clear(m_root);
}

void Tree::p_clear(Node* node) {
  if (!node)return;

  p_clear(node->left);
  p_clear(node->right);
  delete node;
}