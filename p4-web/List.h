#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
    bool empty() const {
        return (first == nullptr && last == nullptr);
    }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
    int size() const {
        return sizeList;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
    T & front() {
        return first->datum;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
    T & back() {
        return last->datum;
    }

  //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum) {
        if (!empty()) {
            Node *victim = first;
            first = new Node;
            first->datum = datum;
            first->next = victim;
            first->prev = nullptr;
            victim->prev = first;
            victim = nullptr;
        }
        else {
            first = new Node;
            first->datum = datum;
            first->next = nullptr;
            first->prev = nullptr;
            last = first;
        }
        ++sizeList;
    }

  //EFFECTS:  inserts datum into the back of the list
    void push_back(const T &datum) {
        if (!empty()) {
            Node *victim = last;
            last = new Node;
            last->datum = datum;
            last->next = nullptr;
            last->prev = victim;
            victim->next = last;
            victim = nullptr;
        }
        else {
            first = new Node;
            first->datum = datum;
            first->next = nullptr;
            first->prev = nullptr;
            last = first;
        }
        ++sizeList;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
    void pop_front() {
        if (sizeList > 1) {
            Node *victim = first;
            first = victim->next;
            first->prev = nullptr;
            delete victim;
            victim = nullptr;
        }
        else {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        --sizeList;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
    void pop_back() {
        if (sizeList > 1) {
            Node *victim = last;
            last = victim->prev;
            last->next = nullptr;
            delete victim;
        }
        else {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        --sizeList;
    }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
    void clear() {
        while(!empty()) {
            pop_front();
        }
    }
    
    List():
    sizeList(0), first(nullptr), last(nullptr) {}
    
    ~List() {
        clear();
    }
    
    List(const List &other) {
        first = nullptr;
        last = nullptr;
        copy_all(other);
    }
    
    List & operator=(const List &other) {
        if (this == &other) {
            return *this;
        }
        else {
            clear();
            copy_all(other);
            return *this;
        }
    }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
    int sizeList;
    
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T> &other) {
        sizeList = 0;
        for (Node *ptr = other.first; ptr != nullptr; ptr = ptr->next) {
            push_back(ptr->datum);
        }
    }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
      
      Iterator():
      node_ptr(nullptr) {}
      
      Iterator& operator++() {
          node_ptr = node_ptr->next;
          return *this;
      }
      
      T& operator*() {
          return node_ptr->datum;
      }
      
      bool operator==(const Iterator rhs) const{
          return (node_ptr == rhs.node_ptr);
      }
      
      bool operator!=(const Iterator rhs) const{
          return (node_ptr != rhs.node_ptr);
      }
      
      Node* getNode() {
          return node_ptr;
      }
      
      void setNull() {
          node_ptr = nullptr;
      }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;

    // construct an Iterator at a specific position
      Iterator(Node *p) {
          node_ptr = p;
      }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
    Iterator end() const {
        return Iterator();
    }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i) {
        Iterator lastEle = Iterator(last);
        if (i == begin()) {
            pop_front();
        }
        else if (i == lastEle) {
            pop_back();
        }
        else {
            --sizeList;
            i.getNode()->prev->next = i.getNode()->next;
            i.getNode()->next->prev = i.getNode()->prev;
            delete i.getNode();
            i.setNull();
        }
    }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T &datum) {
        if (i == begin()) {
            push_front(datum);
        }
        else {
            ++sizeList;
            Node* prevCopy = i.getNode()->prev;
            i.getNode()->prev = new Node;
            i.getNode()->prev->datum = datum;
            i.getNode()->prev->prev = prevCopy;
            prevCopy->next = i.getNode()->prev;
            i.getNode()->prev->next = i.getNode();
            prevCopy = nullptr;
        }
    }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
