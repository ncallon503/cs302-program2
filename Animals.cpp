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


bool Test::operator==(const char * op2) {
  if(strcmp(name.c_str(), op2) == 0) return true;
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
      return input; 
    }
    return input;
}

// end Parent Animal Class

// -----------------------

// Pet Child Class



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
    cout << cName << " has failed their " << temp2 << " mission, taking " << hours << "hours.\n";
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

  cout << cName << " has switched roles and is now a police " << temp2 << " " << temp << ".\n";
  return aType;
}

ostream& operator<<(ostream &output, const PoliceAnimal& src) {
  output << static_cast<const Animal&>(src);

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
  in >> static_cast<Animal&>(src);
  return in;
}

// end Police Animal Child Class

// -----------------------

// Competing Animal Child Class



// end Competing Animal Child Class

#endif // _ANIMALS_CPP_
