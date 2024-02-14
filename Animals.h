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
#include <cstring>
#include <stdexcept>

using namespace std;

enum animalType {
  Dog, Cat, Bird, Fish
};

enum policeType {
  Cadaver, Narcotics, Bomb, Chase
};

class Animal { // Base Parent Animal class
  public:
    Animal();
    Animal(const int anAge, const animalType aType, const char * aName);
    Animal(const Animal& src);
    Animal& operator=(const Animal& op2); // Assignment (sets to)
    ~Animal();
    

    bool operator<(const Animal& op2); // Less than
    bool operator<=(const Animal& op2); // Less than equal
    bool operator>(const Animal& op2); // More than
    bool operator>=(const Animal& op2); // More than equal
    bool operator==(const Animal& op2); // Is equal to
    bool operator!=(const Animal& op2); // Not equal to

    friend istream & operator>>(istream &input, Animal& src); // Input stream overloader
    friend ostream & operator<<(ostream &output, const Animal& src); // Output stream overloader

    Animal operator+(const Animal& op2); // Addition return by value
    Animal & operator+=(const Animal& op2); // I-addition return by reference

  protected:
    int age; // Age of animal, shared with all children
    animalType type; // One of the four types of animals, shared with all children

  private:
    unique_ptr<char[]> name; // Name of the animal, a unique_ptr of a char array, not shared with children

};

/* class Pet: public Animal { // Derived Child Pet class
  public:
    Pet();
    Pet(const string aName, const int anAge, PetType aType);
    Pet(const Pet& aPet);
    Pet operator=(const Pet& aPet);
    ~Pet();
    
    int walk();
    int play();
    int feed();

  private:
    int minutesWalked; // Keeps track of amount of minutes pet is walked
    int affectionLevel; // At a cap of 100, keeps track of how much the animal likes the owner
    int hungerLevel; // Keeps track of how hungry the animal is
    unique_ptr<char[]> name;
};

class PoliceAnimal: public Animal { // Derived Child Police Animal class
  public:
    PoliceAnimal();
    PoliceAnimal(const int anAge, const animalType aType, const policeType aPType, const string aName); // Animal type must be dog or exception occurs, police dogs only
    PoliceAnimal(const PoliceAnimal& src);
    PoliceAnimal operator=(const PoliceAnimal& op2);
    ~PoliceAnimal();

    int goOnMission(); // The police animal goes on a mission and returns the amount of hours served and whether the mission was successful (0 if mission not successful)
    int switchRole(int aRole); // Switches the animals' role, resets the hours and missions completed and returns which role the animal was switched to

  private:
    policeType pType;
    int hoursServed; // Keeps track of hours animal has served in the force
    int missionsCompleted; // Keeps track of how many missions the animal has completed
    int missionsFailed; // Keeps track of how many missions the animal has failed
    string name;
};

class CompAnimal: public Animal { // Derived Child Competing Animal class
  public:
    CompAnimal();
    CompAnimal(const CompAnimal& aCompAnimal);
    CompAnimal operator=(const CompAnimal& aCompAnimal);
    ~CompAnimal();

  private:
    string name;

}; */

#endif // _ANIMALS_H_

