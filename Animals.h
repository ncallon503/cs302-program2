/* Nathan Callon, CS302, 2/5/2024, Karla Fant
I decided to have 3 different types of animals, which will be
pets, service animals, and competitive animals (that compete 
in competitions, of course). By default they will all have a name 
and age, but there will be many differences in the derived classes. */

#ifndef _ANIMALS_H_
#define _ANIMALS_H_

#include <iostream>
#include <memory>
#include <type_traits>
// #include "DLL.tpp"

using namespace std;



enum PetType {
  DOG,
  CAT,
};

class Animal { // Base Parent Animal class
  public:
    
    typedef unique_ptr<Animal> animal_ptr;

    Animal();
    Animal(const string aName, const int anAge);
    Animal(const Animal& anAnimal);
    Animal operator=(const Animal& anAnimal);
    ~Animal();

    animal_ptr & getNext();
    bool setNext(Animal * anAnimal);
    animal_ptr & getPrev();
    bool setPrev(Animal * anAnimal);
    friend ostream & operator<<(ostream &output, const Animal& anAnimal);

  protected:
    string name;
    int age;
    animal_ptr next;
    animal_ptr prev;

  private:

};

class Pet: public Animal { // Derived Child Pet class
  public:
  Pet();
  Pet(const string aName, const int anAge, PetType aType);
  Pet(const Pet& aPet);
  Pet operator=(const Pet& aPet);
  ~Pet();

  protected:

  private:
  PetType type;

};

class ServAnimal: public Animal { // Derived Child Service Animal class
  public:
  ServAnimal();
  ServAnimal(const ServAnimal& aServAnimal);
  ServAnimal operator=(const ServAnimal& aServAnimal);
  ~ServAnimal();

  protected:

  private:

};

class CompAnimal: public Animal { // Derived Child Competitive Animal class
  public:
  CompAnimal();
  CompAnimal(const CompAnimal& aCompAnimal);
  CompAnimal operator=(const CompAnimal& aCompAnimal);
  ~CompAnimal();

  protected:

  private:

};



template <typename T> // This DLL can handle all 3 animal types which is Pets, Service Animals and Competitive Animals, which the user can pass in through an Enum in the main input to choose which type of animal they are interested in learning about and interacting with.
class DLL {
  public:
    DLL();
    ~DLL();

    bool addAnimal(T *anAnimal);
    bool display();
    


  protected:

  private:
    
    unique_ptr<T> ani_head;

};

template <typename T>
bool DLL<T>::display() {
  return true;
}

template <typename T>
DLL<T>::DLL(): ani_head(nullptr) {

}

template <typename T>
DLL<T>::~DLL() {

}

template <typename T>
bool DLL<T>::addAnimal(T *anAnimal) {
  if(!ani_head) {
    ani_head.reset(anAnimal);
    ani_head->setNext(nullptr);
    ani_head->setPrev(nullptr);
    return true;
  }
  if(!ani_head->getNext()) {
    ani_head->setNext(anAnimal);
    anAnimal->setPrev(ani_head.get());
    return true;
  }
  return true;
}


#endif // _ANIMALS_H_
