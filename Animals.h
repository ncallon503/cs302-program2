/* Nathan Callon, CS302, 2/5/2024, Karla Fant
I decided to have 3 different types of animals, which will be
pets, service animals, and competitive animals (that compete 
in competitions, of course). By default they will all have a name 
and age, but there will be many differences in the derived classes. */

#ifndef _ANIMALS_
#define _ANIMALS_

#include <iostream>

using namespace std;

enum PetType {
  DOG,
  CAT,
};

class Animal { // Base Parent Animal class
  public:
    Animal();
    Animal(const string aName, const int anAge);
    Animal(const Animal& anAnimal);
    Animal operator=(const Animal& anAnimal);
    ~Animal();

  protected:
    string name;
    int age;

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





#endif // _ANIMALS_
