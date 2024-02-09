#ifndef _ANIMALS_CPP_
#define _ANIMALS_CPP_

#include "Animals.h"


typedef unique_ptr<Animal> animal_ptr;

Animal::Animal(): name("animal 1"), age(10), next(nullptr), prev(nullptr) {

}

Animal::~Animal() {

}

animal_ptr & Animal::getNext() {
  return this->next;
}

animal_ptr & Animal::getPrev() {
  return this->prev;
}

bool Animal::setNext(Animal * anAnimal) { // Interestingly, raw pointers are passed in but it does not like when unique_ptr's are.
  this->next.reset(anAnimal);
  return true;
}

bool Animal::setPrev(Animal * anAnimal) {
  this->prev.reset(anAnimal);
  return true;
}

ostream& operator<<(ostream &output, const Animal& anAnimal) {
  output << "Name: " << anAnimal.name << ", Age: " << anAnimal.age << "\n";
  return output;
}

#endif // _ANIMALS_CPP_
