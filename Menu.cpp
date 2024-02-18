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

UserMenu::UserMenu() {
  initializeMenus();
}


UserMenu::~UserMenu() {

}

const bool UserMenu::initializeMenus() {
  police.insert(PoliceAnimal(12, policeType::Cadaver, "Shadowfang", 37, 7, 2));
  police.insert(PoliceAnimal(7, policeType::Bomb, "Nova", 32, 5, 1));
  police.insert(PoliceAnimal(9, policeType::Bomb, "Diesel", 29, 4, 1));
  police.insert(PoliceAnimal(14, policeType::Chase, "Avalanche", 78, 14, 1));
  police.insert(PoliceAnimal(6, policeType::Narcotics, "Vortex", 12, 3, 0));
  police.insert(PoliceAnimal(10, policeType::Chase, "Saber", 32, 6, 2));
  return true;
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
  int input = -1; // Menu input
  int role = -1; // Role of animal to change
  string name = ""; // Placeholder name for user selecting animals
  PoliceAnimal tempAnimal;
  while(input != 0) {
    cout << "\nPlease enter one of the following options:\n1. Display all police animals\n2. Remove a police animal\n" << 
    "3. Remove all police animals\n4. Add a police animal\n5. Choose an animal to go on a mission with\n6. Change an animal's role\n0. Exit\n\n";
    input = getInputChoice(0, 6);
    switch(input) {
      case 1:
        cout << police;
      break;
      case 2:
        cout << "\nPlease enter the name of the animal to remove:\n";
        cin >> name;
        police.remove(name.c_str());
        cout << "\n";
      break;
      case 3:
        police.removeAll();
        cout << "\nAll animals removed.\n";
      break;
      case 4:
        cin >> tempAnimal;
        police.insert(tempAnimal);
        cout << tempAnimal;
      break;
      case 5:
        cout << "\nPlease enter the name of the animal to go on a mission with:\n";
        cin >> name;
        cout << "\nYou have entered " << name << "\n";
        if(!police.chooseAni(name.c_str())) {
          cout << "\nNo animal found with specified name.\n";
          return policeMenu();
        }
        police.chooseAni(name.c_str())->getAni().goOnMission();
        cout << "\n";
      break;
      case 6:
        cout << "\nPlease enter the name of the animal you want to change roles of:\n";
        cin >> name;
        cout << "\nYou have entered " << name << "\n";
        if(!police.chooseAni(name.c_str())) {
          cout << "\nNo animal found with specified name.\n";
          return policeMenu();
        }
        cout << "\nPlease enter which role you want to change " << name << " to:\n0. Cadaver\n1. Narcotics\n2. Bomb\n3. Chase\n\n";
        role = getInputChoice(0, 3);
        switch(role) {
          case 0:
            police.chooseAni(name.c_str())->getAni().switchRole(policeType::Cadaver);
          break;
          case 1:
            police.chooseAni(name.c_str())->getAni().switchRole(policeType::Narcotics);
          break;
          case 2:
            police.chooseAni(name.c_str())->getAni().switchRole(policeType::Bomb);
          break;
          case 3:
            police.chooseAni(name.c_str())->getAni().switchRole(policeType::Chase);
          break;
          default:
            cout << "\nUnspecified input.\n";
            return policeMenu();
          break;
        }
        cout << "\n";
      break;
      case 0:
        cout << "\nExiting Police Menu.\n";
        return 1;
      break;
      default:
        cout << "\nInvalid input. Exiting.\n";
        return -1;
      break;
    }
  }
  return policeMenu(); // Recursively return until the user enters 0 (gee, recursion is awesome)
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

    cout << "Please enter an integer between " << minInt << " and " << maxInt << ":\n\n";
    
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
