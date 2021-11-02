#pragma once

/// @tparam data the node will hold
template<typename T=int>
struct Node {
  T data;
  Node* next{nullptr};
  Node* prev{nullptr};
};
