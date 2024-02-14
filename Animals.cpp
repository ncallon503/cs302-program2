#ifndef _ANIMALS_CPP_
#define _ANIMALS_CPP_

#include "Animals.h"

// Parent Animal Class

Animal::Animal(): age(0), type(animalType::Dog), name(nullptr) {
  name.reset(new char[1]); // If the user accidentally couts a nullptr, the whole ostream breaks.
  strcpy(name.get(), "");
}

Animal::Animal(const int anAge, const animalType aType, const char* aName) {
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

    cout << "Enter your animal's name: ";

    string tempName;
    input >> tempName;
  
    src.name.reset(new char [tempName.length() +1]); // Using unique ptr to allocate memory
    strcpy(src.name.get(), tempName.c_str());

    cout << "Enter your animal's age: ";

    input >> src.age;

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
    
    return input;
}

// end Parent Animal Class

// -----------------------

// Pet Child Class



// end Pet Child Class

// -----------------------

// Police Animal Child Class



// end Police Animal Child Class

// -----------------------

// Competing Animal Child Class



// end Competing Animal Child Class

#endif // _ANIMALS_CPP_
