#ifndef _MENU_CPP_
#define _MENU_CPP_

#include"Menu.h"

const char *AnimalException::what() const noexcept {
  return "Animal not found with specified name in list.\n";
}

const char *IntException::what() const noexcept {
  return "Please enter a valid integer.\n";
}

const char *RangeException::what() const noexcept {
  return "The minimum range is larger than the maximum range, please enter valid integer range.\n";
}

const char *PoliceException::what() const noexcept {
  return "The police force currently only allows dogs, please respect this and choose the valid species.\n";
}

const int UserMenu::displayMenu() {
  
  int input = -1;
  while(input != 0) {
    cout << "\n1. Your pet menu \n2. The police force menu\n3. The competitive animal menu\n0. Exit\n\n";
    input = getInputChoice(0, 3);

    switch(input) {
      case 1:
        cout << "Entering pet menu:\n";
        petMenu();
      break;
      case 2:
        cout << "Entering police menu:\n";
        policeMenu();
      break;
      case 3:
        cout << "Entering competition menu:\n";
        compMenu();
      break;
      case 0:
        cout << "Exiting, thanks for your co-operation.\n";
        return 1;
      break;
      default:
        return 1;
      break;
    }
  }

  return 1;
}

const int UserMenu::petMenu() {
  int input = -1;
  while(input != 0) {
    input = getInputChoice(0, 6);
  }
  return 1;
}

const int UserMenu::policeMenu() {
  int input = -1;
  while(input != 0) {
    input = getInputChoice(0, 6);
  }
  return 1;
}

const int UserMenu::compMenu() {
  int input = -1;
  while(input != 0) {
    input = getInputChoice(0, 6);
  }
  return 1;
}

const int UserMenu::getInputChoice(const int minInt, const int maxInt) const {

  try {

    if(minInt > maxInt)
      throw RangeException();

    cout << "Please enter an integer between " << minInt << " and " << maxInt << ":\n";
    
    string input = "";
    cin >> input;

    int integer = stoi(input);
    if(integer < minInt || integer > maxInt)
      throw IntException();

    return integer;
  }
  catch(const IntException& e) {
    cerr << e.what();
    cin.clear();
    return getInputChoice(minInt, maxInt); // Recursively return until the user enters correct input in the range
  }
  catch(const RangeException& e) {
    cerr << e.what();
    cin.clear();
    return 0; // This function cannot work with ranges that have minimums above their maximums etc., so it will return instead of going infinitely
  }
}

#endif // _MENU_CPP_
