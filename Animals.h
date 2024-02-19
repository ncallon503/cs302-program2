/* There is a parent Animal class with an age, type and name that
all the children derive from. The name uses a char array which is set
to private so some of the children can use string classes for their names,
and the children are Pets, Police Animals, and Competitive Animals. They
all have their own special functionalities and Police Animals can only be
of type Dog for the animalType. Another enum is made for the police which
is the category of missions they go on which is Cadaver searching, Narcotics searching,
Bomb missions and Chase missions. */

#ifndef _ANIMALS_H_
#define _ANIMALS_H_

#include <iostream>
#include <memory>
#include <type_traits>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <stdlib.h>

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
    
    bool testFun(const int anAge) {
      cout << "This test works\n\n\n";
      age = anAge;
      cout << "My new age is " << age;
      cout << "My age is " << name.get();
      return true;
    }

    bool operator<(const Animal& op2); // Less than
    bool operator<=(const Animal& op2); // Less than equal
    bool operator>(const Animal& op2); // More than
    bool operator>=(const Animal& op2); // More than equal
    bool operator==(const Animal& op2); // Is equal to
    bool operator==(const char * op2); // Is equal to a name by const char *
    bool operator!=(const char * op2); // Is not equal to a name by const char *
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

class Pet: public Animal { // Derived Child Pet class
  public:
    Pet();
    Pet(const char* aName, const int anAge, animalType aType, const int walked, const int affLevel, const int hunger);
    Pet(const Pet& aPet);
    Pet & operator=(const Pet& aPet);
    ~Pet();
    
    int play(); // plays with the animal, increasing affection level if animal not hungry, but lowering if animal is hungry
    int feed(); // feeds the animal, slightly increases affection but cannot do at max fullness
    
    bool operator==(const char * op2); // Is equal to a name by const char *, this is overloaded because cName is a string
    bool operator!=(const char * op2); // Is not equal to a name by const char *, this is overloaded because cName is a string
    friend ostream& operator<<(ostream &o, const Pet& src);
    friend istream& operator>>(istream& in, Pet& src);

  private:
    int minutesPlayed; // Keeps track of amount of minutes pet is played with
    int affectionLevel; // At a cap of 100, keeps track of how much the animal likes the owner
    int hungerLevel; // Keeps track of how hungry the animal is
    unique_ptr<char[]> cName; // Due to parent's name being private we rename the name to cName here

};


class PoliceAnimal: public Animal { // Derived Child Police Animal class
  public:
    PoliceAnimal();
    PoliceAnimal(const int anAge, const policeType aPType, const string aName, const int hoursServed, const int missionsCompleted, const int missionsFailed); // Animal type must be dog or exception occurs, police dogs only
    PoliceAnimal(const PoliceAnimal& src);
    PoliceAnimal & operator=(const PoliceAnimal& op2);
    ~PoliceAnimal();

    int goOnMission(); // The police animal goes on a mission and returns the amount of hours served and whether the mission was successful (0 if mission not successful)
    policeType switchRole(policeType aType); // Switches the animals' role, resets the hours and missions completed and returns which role the animal was switched to

    bool operator==(const char * op2); // Is equal to a name by const char *, this is overloaded because cName is a string
    bool operator!=(const char * op2); // Is not equal to a name by const char *, this is overloaded because cName is a string
    friend ostream& operator<<(ostream &output, const PoliceAnimal& src);
    friend istream& operator>>(istream& in, PoliceAnimal& src);

  private:
    policeType pType;
    int hoursServed; // Keeps track of hours animal has served in the force
    int missionsCompleted; // Keeps track of how many missions the animal has completed
    int missionsFailed; // Keeps track of how many missions the animal has failed
    string cName;
};

class CompAnimal: public Animal { // Derived Child Competing Animal class
  public:
    CompAnimal();
    CompAnimal(const CompAnimal& src);
    CompAnimal(const int anAge, const animalType aType, const string aName, const int theEventsWon, const int theEventsLost, const vector<string> theTrophies);
    CompAnimal & operator=(const CompAnimal& src);
    ~CompAnimal();

    const double winLossRatio(); // The higher the number the better, this is the ratio of events won vs. lost for animals, prints it and displays it
    const bool competeInEvent(const string event); // The animal competes in an event, and either ends up winning a trophy or losing. Animals that have competed more have a higher chance of winning.
    const int checkStats(); // Displays the specific stats of the competitor listing trophies, events won and lost and more details

    bool operator==(const char * op2); // Is equal to a name by const char *, this is overloaded because cName is a string
    bool operator!=(const char * op2); // Is not equal to a name by const char *, this is overloaded because cName is a string
    friend ostream& operator<<(ostream &o, const CompAnimal& src);
    friend istream& operator>>(istream& in, CompAnimal& src);

  private:
    const int displayTrophies(const long unsigned int index); // Recursive helper to display trophies in vector

    vector<string> trophies; // List of 1st place trophies depending on what user wants to compete their animal in
    int eventsWon; // Counter of how many events the animal has won
    int eventsLost; // Counter of how many the events the animal has lost
    string cName; // Animal's name

}; 

#endif // _ANIMALS_H_

