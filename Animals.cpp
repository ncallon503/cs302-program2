/* This file provides all the definitions for the main star of this program,
the Animals. All the relational operators are overloaded for the Parent Animal class, 
and in addition I chose to overload the binary operators of + and the incremental operator
of += which would increment the age of the animal by said amount. To compare if animals are
equivalent, it would check their name, age and type. The operators that the child also had to
overload are the istream and ostream operators, along with the equal to name operator which
use a const char *, due to the difference between the string and char names. */

#ifndef _ANIMALS_CPP_
#define _ANIMALS_CPP_

#include "Animals.h"

// Parent Animal Class

Animal::Animal(): age(0), type(animalType::Dog), name(nullptr) {
  name.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
  strcpy(name.get(), "");
}

Animal::Animal(const int anAge, const animalType aType, const char* aName) {
  if(aName == nullptr) {
    name.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
    strcpy(name.get(), "");
  }
  age = anAge;
  type = aType;
  name.reset(new char [strlen(aName)+1]);
  strcpy(name.get(), aName);
}

Animal::Animal(const Animal& src): age(src.age), type(src.type) {
  name.reset(new char [strlen(src.name.get()) + 1]);
  strcpy(name.get(), src.name.get());
}

Animal::~Animal() { // unique_ptr automatically clears memory but to demonstrate how useful the reset() function is, this clears it too:
  name.reset();
}

Animal& Animal::operator=(const Animal& src) { // Assignment (sets to)
  if(this == &src) return *this;
  name.reset(new char [strlen(src.name.get()) + 1]);
  strcpy(name.get(), src.name.get());
  age = src.age;
  type = src.type;
  return *this;
}

Animal Animal::operator+(const Animal& op2) { // My overloaded + operator takes op1 and op2's age and adds them, but keeps op1's type and name
  return Animal(age + op2.age, type, name.get());
}

Animal & Animal::operator+=(const Animal& op2) { // I-addition return by reference
  age += op2.age;
  return *this;
}

bool Animal::operator<(const Animal& src) {
  if(age < src.age) return true; // If age is less than src, return true
  else return false; // else return false
}

bool Animal::operator<=(const Animal& src) {
  if(age <= src.age) return true;
  else return false;
}

bool Animal::operator==(const Animal& src) {
  if(age == src.age && (strcmp(name.get(), src.name.get()) == 0) && type == src.type) return true; // Unlike others, only returns true if all age, name, and type are equal
  else return false;
}

bool Animal::operator==(const char * op2) { // Is equal to a name by string
  if(strcmp(name.get(), op2) == 0) return true;
  else return false;
}

bool Animal::operator!=(const char * op2) { // Is equal to a name by string
  if(!(strcmp(name.get(), op2) == 0)) return true;
  else return false;
}

bool Animal::operator>(const Animal& src) {
  if(age > src.age) return true;
  else return false;
}

bool Animal::operator>=(const Animal& src) {
  if(age >= src.age) return true;
  else return false;
}

bool Animal::operator!=(const Animal& src) {
  if((age != src.age) || !(strcmp(name.get(), src.name.get()) == 0) || (type != src.type)) return true; // Another unique case, compares all 3 attributes and if any are different returns false
  else return false;
}

ostream& operator<<(ostream &output, const Animal& src) {
  string temp = "";
  switch(src.type) {
    case 0:
      temp = "dog";
      break;
    case 1:
      temp = "cat";
      break;
    case 2:
      temp = "bird";
      break;
    case 3:
      temp = "fish";
      break;
    default:
      break;
  }

  output << src.name.get() << " the " << src.age << " year old " << temp;
  return output;
}

istream & operator>>(istream &input, Animal& src) { // Input stream
    try {

      cout << "Enter your animal's name: ";

      string tempName;
      input >> tempName;
    
      src.name.reset(new char [tempName.length() +1]); // Using unique ptr to allocate memory
      strcpy(src.name.get(), tempName.c_str());


      string tempAge = "-1";
      while(stoi(tempAge) < 0) {
        cout << "Enter your animal's age: ";
        input >> tempAge;
      }

      src.age = stoi(tempAge);

      string temp = "-1";

      while((temp != "0") && (temp != "1") && (temp != "2") && (temp != "3")) {
        cout << "Enter your animal's type:\n 0. Dog\n 1. Cat\n 2. Bird\n 3. Fish\n";
        temp = "";
        input >> temp;
      }

      switch(stoi(temp)) {
      case 0:
        src.type = animalType::Dog;
        break;
      case 1:
        src.type = animalType::Cat;
        break;
      case 2:
        src.type = animalType::Bird;
        break;
      case 3:
        src.type = animalType::Fish;
        break;
      default:
        break;
      }
    } catch (const exception &e) {
      cout << e.what() << "\n";
      input.clear();
      input >> src;
      return input;
    }
    return input;
}

// end Parent Animal Class

// -----------------------

// Pet Child Class

Pet::Pet(): Animal(), minutesPlayed(0), affectionLevel(50), hungerLevel(50) {
  cName.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
  strcpy(cName.get(), "");
}

Pet::Pet(const char* aName, const int anAge, animalType aType, const int played, const int affLevel, const int hunger): Animal(anAge, aType, aName) {
  if(aName == nullptr) {
    cName.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
    strcpy(cName.get(), "");
  }
  cName.reset(new char[strlen(aName) + 1]);
  strcpy(cName.get(), aName);
  minutesPlayed = played;
  affectionLevel = affLevel;
  hungerLevel = hunger;
  age = anAge;
  type = aType;
}

Pet::Pet(const Pet& aPet): Animal(aPet), minutesPlayed(aPet.minutesPlayed), affectionLevel(aPet.affectionLevel), hungerLevel(aPet.hungerLevel)  {
  if(aPet.cName == nullptr) {
    cName.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
    strcpy(cName.get(), "");
  }
  cName.reset(new char[strlen(aPet.cName.get()) + 1]);
  strcpy(cName.get(), aPet.cName.get());
}

Pet & Pet::operator=(const Pet& aPet) {
  if(aPet.cName == nullptr) {
    cName.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
    strcpy(cName.get(), "");
  }
  cName.reset(new char[strlen(aPet.cName.get()) + 1]);
  strcpy(cName.get(), aPet.cName.get());
  minutesPlayed = aPet.minutesPlayed;
  affectionLevel = aPet.affectionLevel;
  hungerLevel = aPet.hungerLevel;
  age = aPet.age;
  type = aPet.type;
  return *this;
}

Pet::~Pet() {
  cName.reset(); // Reset just in case to clear memory
}

int Pet::play() {
  int minutes = (rand() % 30) + 30; // Random number of minutes between 30 and 60
  if(hungerLevel >= 80) {
    cout << cName.get() << " is too hungry to play.\n";
    hungerLevel += 5;
    return 0;
  }
  if(hungerLevel >= 50) {
    int affLevelChange = (rand() % 15) + 5; // Affection level decrease from 5 to 20
    cout << cName.get() << " is hungry, but plays with you for " << minutes << " minutes and their affection level is wavering due to hunger, decreasing by " << affLevelChange << " points.\n";
    hungerLevel += 25;
    affectionLevel -= affLevelChange;
    minutesPlayed += minutes;
    return minutes;
  } else {
    int affLevelChange = (rand() % 20) + 8; // Affection level increase from 8 to 28
    cout << cName.get() << " plays with you for " << minutes << " minutes and their affection level has increased by " << affLevelChange << ".\n";
    hungerLevel += 15;
    affectionLevel -= affLevelChange;
    minutesPlayed += minutes;
    return minutes;
  } 
  return 1;
}

int Pet::feed() {

  int affLevelChange = (rand() % 5) + 5; // Affection level increase from 5 to 10
  int hungDec = (rand() % 10) + 10; // Hunger level decrease amount between 10 and 20
  if(hungerLevel <= 5) {
    cout << cName.get() << " is too full to eat right now.\n";
    return 0;
  }
  if(hungerLevel <= 20) { // Decreases hunger level to 0
    cout << "After feeding " << cName.get() << " they are completely full, not hungry anymore, and affection is increased by " << affLevelChange << ".\n";
    hungerLevel = 0;
    affectionLevel += affLevelChange;
    return 0;
  } else {
    cout << "You have fed " << cName.get() << " and their hunger level has decreased by " << hungDec << ", affection increased by " << affLevelChange << ".\n";
    hungerLevel -= hungDec;
    affectionLevel += affLevelChange;
    return hungDec;
  }
  return 1;
}

bool Pet::operator==(const char * op2) {
  if(strcmp(cName.get(), op2) == 0) return true;
  return false;
}

bool Pet::operator!=(const char * op2) {
  if(!(strcmp(cName.get(), op2) == 0)) return true;
  return false;
}

ostream& operator<<(ostream &o, const Pet& src) {
  string temp = "", temp2 = "";

  switch(src.type) {
    case 0:
      temp = "dog";
      break;
    case 1:
      temp = "cat";
      break;
    case 2:
      temp = "bird";
      break;
    case 3:
      temp = "fish";
      break;
    default:
      break;
  }

  o << src.cName.get() << " the " << src.age << " year old " << temp << " has played with you for " << src.minutesPlayed << " minutes, has a hunger level of " << src.hungerLevel << ", and affection level of " << src.affectionLevel << ".\n";
  return o;
}

istream& operator>>(istream& in, Pet& src) {
  try {
  
    src.affectionLevel = 50;
    src.minutesPlayed = 0;
    src.hungerLevel = 45; // These should all be reset so this can be a fresh start for the animal

    cout << "Enter the pet's name: ";

    string tempName;
    in >> tempName;
  
    src.cName.reset(new char[strlen(tempName.c_str()) + 1]);
    strcpy(src.cName.get(), tempName.c_str());

    string tempAge = "-1";
    while(stoi(tempAge) < 0) {
      cout << "Enter the pet's age: ";
      in >> tempAge;
    }

    src.age = stoi(tempAge);
   
    string temp;

    while((temp != "0") && (temp != "1") && (temp != "2") && (temp != "3")) {
      cout << "Enter the type of pet you want:\n 0. Dog \n 1. Cat\n 2. Bird\n 3. Fish\n";
      temp = "";
      in >> temp;
    }

    switch(stoi(temp)) {
      case 0:
        src.type = animalType::Dog;
        break;
      case 1:
        src.type = animalType::Cat;
        break;
      case 2:
        src.type = animalType::Bird;
        break;
      case 3:
        src.type = animalType::Fish;
        break;
      default:
        break;
      }

    return in;

  } catch (const exception &e) {
    cout << e.what() << "\n";
    in.clear();
    in >> src;
    return in;
  }

  return in;
}

// end Pet Child Class

// -----------------------

// Police Animal Child Class

PoliceAnimal::PoliceAnimal(): Animal(), pType(policeType::Bomb), hoursServed(0), missionsCompleted(0), missionsFailed(0), cName("")  {
}

PoliceAnimal::PoliceAnimal(const int anAge, const policeType aPType, const string aName, const int theHoursServed, const int theMissionsCompleted, const int theMissionsFailed): Animal(anAge, animalType::Dog, aName.c_str()), pType(aPType), hoursServed(theHoursServed), missionsCompleted(theMissionsCompleted), missionsFailed(theMissionsFailed), cName(aName) {
}

PoliceAnimal::PoliceAnimal(const PoliceAnimal& src) {
  *this = src;
}

PoliceAnimal & PoliceAnimal::operator=(const PoliceAnimal& op2) {
  if(this == &op2) return *this;
  Animal::operator=(op2);
  cName = op2.cName;
  pType = op2.pType;
  hoursServed = op2.hoursServed;
  missionsCompleted = op2.missionsCompleted;
  missionsFailed = op2.missionsFailed;
  return *this;
}

PoliceAnimal::~PoliceAnimal() {
}


bool PoliceAnimal::operator==(const char * op2) {
  if(strcmp(cName.c_str(), op2) == 0) return true; // Converting cName to string for compare operator
  else return false;
}

bool PoliceAnimal::operator!=(const char * op2) {
  if(!(strcmp(cName.c_str(), op2) == 0)) return true; // Converting cName to string for compare operator
  else return false;
}

int PoliceAnimal::goOnMission() { // The police animal goes on a mission and returns the amount of hours served and whether the mission was successful (0 if mission not successful)
  int randNumber = ((rand() % 70) + hoursServed);
  int hours = (rand() % 20) + 5;
  hoursServed += hours;

  string temp2 = "";

  switch(pType) {
    case 0:
      temp2 = "Cadaver";
      break;
    case 1:
      temp2 = "Narcotics";
      break;
    case 2:
      temp2 = "Bomb";
      break;
    case 3:
      temp2 = "Chase";
      break;
    default:
      break;
  }
  if(randNumber >= 50) {
    cout << cName << " has completed their " << temp2 << " mission in " << hours << " hours.\n";
    missionsCompleted += 1;
  } else {
    cout << cName << " has failed their " << temp2 << " mission, taking " << hours << " hours.\n";
    missionsFailed += 1;
  }
  return hours;
}

policeType PoliceAnimal::switchRole(policeType aType) { // Switches the animals' role, resets the hours and missions completed and returns which role the animal was switched to
  pType = aType;
  hoursServed = 0;
  missionsCompleted = 0;
  missionsFailed = 0;


  string temp = "", temp2 = "";

  switch(type) {
    case 0:
      temp = "dog";
      break;
    case 1:
      temp = "cat";
      break;
    case 2:
      temp = "bird";
      break;
    case 3:
      temp = "fish";
      break;
    default:
      break;
  }

  switch(pType) {
    case 0:
      temp2 = "Cadaver";
      break;
    case 1:
      temp2 = "Narcotics";
      break;
    case 2:
      temp2 = "Bomb";
      break;
    case 3:
      temp2 = "Chase";
      break;
    default:
      break;
  }

  cout << cName << " has switched roles and is now a police " << temp2 << " " << temp << ", hours and missions have been reset.\n";
  return aType;
}

ostream& operator<<(ostream &output, const PoliceAnimal& src) {
  string temp = "", temp2 = "";

  switch(src.type) {
    case 0:
      temp = "dog";
      break;
    case 1:
      temp = "cat";
      break;
    case 2:
      temp = "bird";
      break;
    case 3:
      temp = "fish";
      break;
    default:
      break;
  }

  switch(src.pType) {
    case 0:
      temp2 = "Cadaver";
      break;
    case 1:
      temp2 = "Narcotics";
      break;
    case 2:
      temp2 = "Bomb";
      break;
    case 3:
      temp2 = "Chase";
      break;
    default:
      break;
  }

  output << src.cName << " the " << src.age << " year old " << temp2 << " Police " << temp << " has " << src.hoursServed << " hours served, " << src.missionsCompleted << " missions completed, and " << src.missionsFailed << " missions failed.\n";
  return output;
}

istream& operator>>(istream& in, PoliceAnimal& src) {
  try {
  
    src.hoursServed = 0;
    src.missionsCompleted = 0;
    src.missionsFailed = 0; // These should all be reset so this can be a fresh start for the animal

    cout << "Enter the Police name: ";

    string tempName;
    in >> tempName;
  
    src.cName = tempName;

    string tempAge = "-1";
    while(stoi(tempAge) < 0) {
      cout << "Enter your animal's age: ";
      in >> tempAge;
    }

    src.age = stoi(tempAge);
   
    src.type = animalType::Dog; // Animal type will always be a dog for police units

    string temp;

    while((temp != "0") && (temp != "1") && (temp != "2") && (temp != "3")) {
      cout << "Enter the unit your animal will be in:\n 0. Cadaver \n 1. Narcotics\n 2. Bomb\n 3. Chase\n";
      temp = "";
      in >> temp;
    }

    switch(stoi(temp)) {
      case 0:
        src.pType = policeType::Cadaver;
        break;
      case 1:
        src.pType = policeType::Narcotics;
        break;
      case 2:
        src.pType = policeType::Bomb;
        break;
      case 3:
        src.pType = policeType::Chase;
        break;
      default:
        break;
      }

    return in;

  } catch (const exception &e) {
    cout << e.what() << "\n";
    in.clear();
    in >> src;
    return in;
  }

  return in;
}

// end Police Animal Child Class

// -----------------------

// Competing Animal Child Class

CompAnimal::CompAnimal(): Animal(), trophies{}, eventsWon(0), eventsLost(0), cName("") {}

CompAnimal::CompAnimal(const CompAnimal& src): Animal(src), trophies(src.trophies), eventsWon(src.eventsWon), eventsLost(src.eventsLost), cName(src.cName) {}

CompAnimal::CompAnimal(const int anAge, const animalType aType, const string aName, const int theEventsWon, const int theEventsLost, const vector<string> theTrophies): Animal(anAge, aType, aName.c_str()), trophies(theTrophies), eventsWon(theEventsWon), eventsLost(theEventsLost), cName(aName) { }

CompAnimal & CompAnimal::operator=(const CompAnimal& src) {
  Animal::operator=(src);
  trophies = vector<string>(src.trophies);
  eventsWon = src.eventsWon;
  eventsLost = src.eventsLost;
  cName = src.cName;
  return *this;
}

CompAnimal::~CompAnimal() {}

const double CompAnimal::winLossRatio() {
  double ratio = eventsWon / eventsLost; // Ratio determined by wins vs losses
  return ratio;
}

const bool CompAnimal::competeInEvent(const string event) {
  int eventsCompeted = eventsWon + eventsLost;
  int chance = (rand() % 10) + eventsCompeted + 40; // Base chance of 40-50% of winning, increased by the amount of events already competed in (more experience the better)
  cout << "\n" << cName << " is competing in the " << event << " event.\n";
  if((rand() % 100) >= chance) { // Event failed, events lost incremented by 1
    eventsLost += 1;
    cout << cName << " has sadly failed in the event, making a total of " << eventsWon << " events won and " << eventsLost << " events lost.\n";
    return false;
  } // Otherwise event success
  eventsWon += 1; // Event won, events won incremented by one and trophy added of event to vector
  cout << cName << " has successfuly got 1st place in the " << event << " event, getting a trophy for it and making a total of " << eventsWon << " events won and " << eventsLost << " events lost!\n";
  trophies.push_back(event);
  return true;
}

const int CompAnimal::checkStats() {
  if(trophies.empty()) {
    cout << cName << " has " << eventsWon << " events won, " << eventsLost << " events lost, competing in a total of " << eventsWon + eventsLost << " events, and has not won any trophies yet.\n";
    return eventsWon + eventsLost;
  }
  cout << cName << " has " << eventsWon << " events won, " << eventsLost << " events lost, competing in a total of " << eventsWon + eventsLost << " events, and has won the following trophies:\n";
  displayTrophies(0);
  cout << "\n";
  return eventsWon + eventsLost;
}

const int CompAnimal::displayTrophies(const long unsigned int index) { // long unsigned int because vector uses this for its size() method
  if(index == trophies.size()) // Base case of traveling through vector
    return index;
  cout << trophies[index] << " trophy\n";
  return displayTrophies(index + 1);
}

bool CompAnimal::operator==(const char * op2) {
  if(strcmp(cName.c_str(), op2) == 0) return true;
  else return false;
}

bool CompAnimal::operator!=(const char * op2) {
  if(!(strcmp(cName.c_str(), op2) == 0)) return true;
  else return false;
}

ostream& operator<<(ostream &o, const CompAnimal& src) {
  string temp = "";

  switch(src.type) {
    case 0:
      temp = "dog";
      break;
    case 1:
      temp = "cat";
      break;
    case 2:
      temp = "bird";
      break;
    case 3:
      temp = "fish";
      break;
    default:
      break;
  }

  o << src.cName << " the " << src.age << " year old " << temp << " has competed in a total of " << src.eventsWon + src.eventsLost << " events, winning " << src.eventsWon << " of them and losing " << src.eventsLost << ".\n";   
  return o;
}

istream& operator>>(istream& in, CompAnimal& src) {

  try {
  
    src.trophies.clear();
    src.eventsWon = 0;
    src.eventsLost = 0; // These should all be reset so this can be a fresh start for the animal

    cout << "Enter the competitor's name: ";

    string tempName;
    in >> tempName;
  
    src.cName = tempName;

    string tempAge = "-1";
    while(stoi(tempAge) < 0) {
      cout << "Enter your animal's age: ";
      in >> tempAge;
    }

    src.age = stoi(tempAge);
   
    string temp;

    while((temp != "0") && (temp != "1") && (temp != "2") && (temp != "3")) {
      cout << "Enter the type of animal:\n 0. Dog \n 1. Cat\n 2. Bird\n 3. Fish\n";
      temp = "";
      in >> temp;
    }

    switch(stoi(temp)) {
      case 0:
        src.type = animalType::Dog;
        break;
      case 1:
        src.type = animalType::Cat;
        break;
      case 2:
        src.type = animalType::Bird;
        break;
      case 3:
        src.type = animalType::Fish;
        break;
      default:
        break;
      }

    return in;

  } catch (const exception &e) {
    cout << e.what() << "\n";
    in.clear();
    in >> src;
    return in;
  }

  return in;
}

// end Competing Animal Child Class

#endif // _ANIMALS_CPP_
