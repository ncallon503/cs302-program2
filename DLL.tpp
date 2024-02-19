/* This is included from the DLL.h file due to the compiler not being able
to compile .tpp files. This defines all the functionality of the Node and DLL
classes and their functions such as the ability to get the next and previous pointers,
insert, display, remove, and more. */

#pragma once

#include "DLL.h"

// Node<T> class

template <typename T>
Node<T>::Node(): next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(const T& anAni): next(nullptr), prev(nullptr) {
  animal = anAni;
}

template <typename T> // Animal is not dynamic memory (even though it has dynamic memory which is managed by unique_ptr) so we don't need to delete
Node<T>::~Node() {

}

template <typename T>
T& Node<T>::getAni() {
  return animal;
}


template <typename T>
Node<T> *Node<T>::getNext() {
  return next;
}

template <typename T>
Node<T> *Node<T>::getPrev() {
  return prev;
}

template <typename T>
bool Node<T>::setNext(Node<T>* aNode) {
  next = aNode;
  return true;
}

template <typename T>
bool Node<T>::setPrev(Node<T>* aNode) {
  prev = aNode;
  return true;
}

// end Node<T> class

// ---------------------------------

// DLL<T> class

template <typename T>
Node<T> * DLL<T>::chooseAni(const char* aName) {
  if(!head) {
    cout << "Empty list, no animals to choose.\n";
    return nullptr;
  }
  return chooseAniFinder(aName, head);
}

template <typename T>
Node<T> * DLL<T>::chooseAniFinder(const char* aName, Node<T> *aNode) {
  if(!aNode) {
    cout << "List traversed with no valid name.\n";
    return nullptr;
  }
  if(aNode->getAni() == aName) return aNode;
  return chooseAniFinder(aName, aNode->getNext());
}

template <typename T>
DLL<T>::DLL(): head(nullptr), tail(nullptr) {

}

template <typename T>
DLL<T>::~DLL() {
  removeAll();
}

template <typename T>
bool DLL<T>::remove(const char* aName) {
  if(!head) return false;
  return removeNameHelper(head, aName);
}

template <typename T>
bool DLL<T>::removeNameHelper(Node<T> *aNode, const char* aName) { 
  if(!aNode) {
    cout << "Traveled through list and could not find specified animal to remove. Try a new name?\n";
    return false;
  }
  if(aNode->getAni() == aName) {
    if(aNode == head) { // If head matches
      head = aNode->getNext();
      if(head)
        head->setPrev(nullptr);
      else
        tail = nullptr;
    } else if(aNode == tail) { // If tail matches
      tail = tail->getPrev();
      tail->setNext(nullptr);
    } else { // If in the middle
      aNode->getPrev()->setNext(aNode->getNext());
      aNode->getNext()->setPrev(aNode->getPrev());
    }
    delete aNode; // Now delete after changing all the pointers, using aNode as the hold
    aNode = nullptr;
    
    return true;
  }
  return removeNameHelper(aNode->getNext(), aName); // Recursively return next
}

template <typename T>
bool DLL<T>::removeAll() {
  if(!head) return false;
  bool ret = removeNext(head);
  head = nullptr;
  tail = nullptr;
  return ret;
}

template <typename T>
bool DLL<T>::removeNext(Node<T> *aNode) {
  if(!aNode) return true;
  removeNext(aNode->getNext()); // Recursively calls repeatedly, then deletes all the nodes once called back
  delete aNode;
  return true;
}

template <typename T>
bool DLL<T>::insert(T anAni) {
  if(!head) { // Case if no nodes in list
    head = new Node<T>(anAni);
    tail = head;
    return true;
  }
  if(!head->getNext()) { // If one node in list
    if(anAni >= head->getAni()) { // If T greater than head, insert after
      head->setNext(new Node<T>(anAni));
      tail = head->getNext();
      tail->setPrev(head);
      return true;
    } else { // else insert before and set tail
      Node<T> *temp = new Node<T>(anAni);
      tail = head;
      tail->setPrev(temp);
      head = temp;
      head->setNext(tail);
      return true;
    }
  }
  // Head comparison so recursive helper calls don't have pointless overhead comparing for head repeatedly
  if(anAni < head->getAni()) {
    Node<T> *temp = new Node<T>(anAni);
    head->setPrev(temp);
    temp->setNext(head);
    head = head->getPrev();
    return true;
  }
  return insert(anAni, head->getNext()); // Recursive helper call
}

template <typename T>
bool DLL<T>::insert(T anAni, Node<T> *aNode) {
  if(aNode == nullptr) { // This means it reached the end of the list without finding something larger than it, so it sets it to the new tail
    Node<T> *temp = new Node<T>(anAni);
    tail->setNext(temp);
    temp->setPrev(tail);
    tail = temp;
    return true;
  }

  if(anAni < aNode->getAni()) { // Keeps the list sorted by only inserting if T is less than the node's T it's comparing to
    Node<T> *temp = new Node<T>(anAni);
    aNode->getPrev()->setNext(temp);
    aNode->setPrev(temp);
    temp->setNext(aNode);
    return true;
  }
  return insert(anAni, aNode->getNext()); // Recursively traverses next
}

template <typename T>
bool DLL<T>::display() {
    if(!head || !tail) { // No animals in the list
      cout << "\nNo animals are in this list.\n";
      return false;
    }
      cout << "\nDisplaying animals:\n\n";
    bool ret = displayNext(head);
    cout << "\n";
    return ret;
}

template <typename T>
bool DLL<T>::displayNext(Node<T> *aNode) {
  cout << aNode->getAni();
  if(aNode->getNext()) {
    cout << "\n";
    return displayNext(aNode->getNext());
  } else return true;
}

template <typename A>
ostream& operator<<(ostream& out, DLL<A>& aDLL) {
  aDLL.display();
  return out;
}

template <typename A>
istream& operator>>(istream& in, DLL<A>& src) {
  A anAnimal;
  in >> anAnimal;
  src.insert(anAnimal);
  return in;
}



