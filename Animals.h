#ifndef _ANIMALS_
#define _ANIMALS_

#include <iostream>

using namespace std;



class Animal {
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

class Pet: public Animal {
  public:
  Pet();
  Pet(const Pet& aPet);
  Pet operator=(const Pet& aPet);
  ~Pet();

  protected:

  private:

};

class ServAnimal: public Animal {
  public:
  ServAnimal();
  ServAnimal(const ServAnimal& aServAnimal);
  ServAnimal operator=(const ServAnimal& aServAnimal);
  ~ServAnimal();

  protected:

  private:

};

class CompAnimal: public Animal {
  public:
  CompAnimal();
  CompAnimal(const CompAnimal& aCompAnimal);
  CompAnimal operator=(const CompAnimal& aCompAnimal);
  ~CompAnimal();

  protected:

  private:

};





#endif // _ANIMALS_
