/* This file defines the Doubly Linked List and Node classes
which both use templates so they can store any type of class,
in this case Animals and their child (even though base Animals are 
not used in the program). The doubly linked list has nodes of next
and previous pointers and is always sorted by age due to the insert
method using the overloaded operators to check where to insert
at the correct spot, and you can search for animals and remove/perform
actions on them by name. */

#pragma once

#include"Animals.h"

// Node<T> class

template <typename T>
class Node { // Node and DLL class don't have children so neither have protected, just public/private
  public:
    Node<T>();
    Node<T>(const T& anAni);
    ~Node<T>();
    Node<T> *getNext();
    Node<T> *getPrev();
    bool setNext(Node<T>* aNode);
    bool setPrev(Node<T>* aNode);
    T& getAni(); // Return by const reference to not duplicate/return value, and const so it's not modified by client, more efficient
  private:
    T animal; // Animal can be any type of the 4 animals
    Node<T> *next;
    Node<T> *prev;
};

// end Node<T> class

// ---------------------------------

// DLL<T> class

template <typename T>
class DLL {
  public:
    DLL<T>();
    ~DLL<T>();

    bool insert(T anAni); // Passes in an animal and creates a node with it using the overloaded assignment operator
    bool remove(const char* aName); // removes based on name
    bool removeAll(); // removes all animals
    bool display(); // displays all animals
    
    Node<T> *chooseAni(const char* aName);

    template <typename A>
    friend ostream& operator<<(ostream& out, DLL<A>& aDLL); // Overloads ostream operator and needs Template A for declaring outside of class
    template <typename A>
    friend istream& operator>>(istream& in, DLL<A>& src); // Overloads istream operator, uses Template A for same reason

  public:
    Node<T> *chooseAniFinder(const char* aName, Node<T> *aNode);
  private:
    
    bool insert(T anAni, Node<T> *aNode);
    bool removeNext(Node<T> *aNode); // Helper for removeAll to remove all nodes
    bool removeNameHelper(Node<T> *aNode, const char* aName); // Helper for traversing to remove by name
    bool displayNext(Node<T> *aNode); // Recursive helper for display() function

    Node<T> *head;
    Node<T> *tail;

};
    
#include "DLL.tpp"


// end DLL<T> class

