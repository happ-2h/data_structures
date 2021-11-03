/*
  TODO:
    -Operator+ links two lists
    -Operator[] replace T get(<index>) and add(T)

    -Copy constructor

    -Permanent reverse
    -Permanent split
    --Non permanent
    ---🤔 make a ✅deep copy or both related??

    -remove(<index>)
 */

#pragma once

// SYS_LIBS
#include <iostream>
#include <initializer_list>

// user_LIBS
#include "Node.h"

template<typename T=int>
class LinkedList {
  private:
    Node<T>* m_head{nullptr};
    std::size_t m_length{0};

  public:
    LinkedList() = default;

    LinkedList(T data) {
      m_head = new Node<T>;
      m_head->data = data;
      m_head->next = nullptr;
      ++m_length;
    }
    LinkedList(std::initializer_list<T> list) {
      for (const auto& e : list) {
        add(e);
      }
    }

    // LATER
    LinkedList(const LinkedList& list) = delete;

    ~LinkedList(){
      clear();
    }

    /**
     * Adds to the list.
     * IMPORTANT: Might replace with []
     * 
     * Nodes are pushed from the back/end.
     * 
     * @tparam data the node will hold
     */
    void add(T data) {
      // Create head if doesn't exist
      if (!m_head) {
        m_head = new Node<T>;
        m_head->data = data;
        m_head->next = nullptr;
        ++m_length;
      }
      // If it does, traverse to end then add
      else {
        Node<T>* new_node = new Node<T>;
        new_node->data = data;
        new_node->next = nullptr;

        if (!m_head->next)
          m_head->next = new_node;
        else {
          Node<T>* temp = m_head->next;

          while(temp->next) {
            temp=temp->next;
          }
          temp->next = new_node;
          ++m_length;
        }
      }
    }

    // TEMP
    T get(std::size_t index=0) const try {
      if (!m_head)
        throw std::out_of_range{"\nget(<index>): attempted to index an empty list\n"};
      if (index > m_length)
        throw std::out_of_range{"\nget(<index>): index is larger than list of length " + std::to_string(m_length) + "\n"};

      if (index == 0) return m_head->data;

      Node<T>* temp = m_head->next;
      for (std::size_t i{1}; i < index; ++i) {
        temp=temp->next;
      }

      return temp->data;
    } catch (const std::out_of_range& e) {
      std::cerr << e.what();

      return static_cast<T>(0);
    }

    std::size_t length() const noexcept {
      return m_length;
    }

    // LATER
    void remove(T data) {
      if (m_head->data == data) {
        Node<T>* delete_node = m_head;
        m_head = m_head->next;
        delete delete_node;
        delete_node = nullptr;
      }
      else {
        Node<T>* temp = m_head->next;
        Node<T>* prev = m_head;

        while(temp) {
          if (temp->data == data) {
            Node<T>* next = temp->next;
            prev->next = next;
            delete temp;
            temp=nullptr;

            break;
          }
          else {
            prev=prev->next;
            temp=temp->next;
          }
        }
        
      }
    }

    void clear() {
      if (!m_head) return;

      Node<T>* temp = m_head->next;

      while(temp) {
        delete m_head;
        m_head = temp;
        temp = m_head->next;
        --m_length;
      }
      if (m_head) {
        delete m_head;
        m_head = nullptr;
        m_length = 0;
      }
    }

    /// Prints the entire list
    void print() {
      Node<T>* temp = m_head;

      while(temp) {
        std::cout << temp->data << "->";
        temp=temp->next;
      }
      std::cout << "nullptr\n";
    }
};
