#ifndef _DLL_H_
#define _DLL_H_

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
class DLL {
  public:
    DLL<T>();
    ~DLL<T>();

    bool insert(const T anAni); // Passes in an animal and creates a node with it using the overloaded assignment operator
    bool remove(const char* aName); // removes based on name
    bool removeAll(); // removes all animals
    bool display(); // displays all animals
    
    Node<T> *chooseAni(const char* aName);

    template <typename A>
    friend ostream& operator<<(ostream& out, const DLL<A>& src); // Overloads ostream operator and needs Template A for declaring outside of class

  public:
    Node<T> *chooseAniFinder(const char* aName, Node<T> *aNode);
  private:
    bool removeNext(Node<T> *aNode); // Helper for removeAll to remove all nodes
    bool removeNameHelper(Node<T> *aNode, const char* aName); // Helper for traversing to remove by name
    bool displayNext(Node<T> *aNode); // Recursive helper for display() function

    Node<T> *head;
    Node<T> *tail;

};

template <typename T>
Node<T> * DLL<T>::chooseAni(const char* aName) {
  if(!head) {
    cout << "Empty list. Returning nullptr\n";
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
  if(2 == 2) {
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
bool DLL<T>::insert(const T anAni) {
  if(!head) {
    head = new Node<T>(anAni);
    tail = head;
    return true;
  }
  if(!head->getNext()) {
    head->setNext(new Node<T>(anAni));
    tail = head->getNext();
    tail->setPrev(head);
    return true;
  }
  Node<T> *toSet = new Node<T>(anAni);
  toSet->setPrev(tail);
  tail->setNext(toSet);
  tail = toSet;
  return true;
}

template <typename T>
bool DLL<T>::display() {
    if(!head || !tail) {
      cout << "\nNo animals are in this list.\n";
      return false;
    }
      cout << "\nDisplaying animals:\n";
    bool ret = displayNext(head);
    cout << "\n";
    return ret;
}

template <typename T>
bool DLL<T>::displayNext(Node<T> *aNode) {
  cout << aNode->getAni();
  if(aNode->getNext()) {
    cout << ",\n";
    return displayNext(aNode->getNext());
  } else return true;
}

template <typename A>
ostream& operator<<(ostream& out, const DLL<A>& aDLL) {
  aDLL.display();
  return out;
}





























// end DLL<T> class

#endif // _DLL_H_
