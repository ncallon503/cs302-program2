/* The User Menu contains three Doubly Linked Lists, one of type Pet,
one of type Police Animal, and one of type Competing Animal. These are
all managed through the menu and the public functions that the Animals
give. They are pre-initialized with Animals so the user has an idea
of what the menu's purpose is. */

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
  pet.insert(Pet("Bark", 10, animalType::Dog, 15, 56, 90));
  pet.insert(Pet("Meow", 6, animalType::Cat, 27, 60, 15));
  pet.insert(Pet("Chirp", 7, animalType::Bird, 12, 56, 45));
  pet.insert(Pet("Bloop", 14, animalType::Fish, 18, 42, 67));
  pet.insert(Pet("Sunfire", 12, animalType::Dog, 11, 58, 23));
  comp.insert(CompAnimal(5, animalType::Dog, "Ironhide", 3, 1, { "Dog Race", "Eating Competition", "Height Contest" }));
  comp.insert(CompAnimal(8, animalType::Cat, "Celest", 1, 1, { "Stealth Contest" }));
  comp.insert(CompAnimal(9, animalType::Fish, "Swimmer", 2, 0, { "Swimming Competition", "Hoop Jumping" }));
  comp.insert(CompAnimal(17, animalType::Bird, "Tempest", 4, 3, { "Flying Contest", "Altitude Contest", "Obstacle Course", "Hunting Competition" }));
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
  int input = -1; // Menu input
  string name = ""; // Placeholder name for user selecting animals
  Pet tempAnimal;
  while(input != 0) {
    cout << "\nPlease enter one of the following options:\n1. View all of your pets\n2. Give away a pet\n" << 
    "3. Give away all your pets\n4. Adopt a pet\n5. Walk with one of your pets\n6. Feed one of your pets\n0. Exit\n\n";
    input = getInputChoice(0, 6);
    switch(input) {
      case 1:
        cout << pet;
      break;
      case 2:
        cout << "\nPlease enter the name of the animal to remove:\n";
        cin >> name;
        pet.remove(name.c_str());
        cout << "\n";
      break;
      case 3:
        pet.removeAll();
        cout << "\nAll pets removed.\n";
      break;
      case 4:
        cin >> tempAnimal;
        pet.insert(tempAnimal);
        cout << tempAnimal;
      break;
      case 5:
        cout << "\nWhich pet do you want to play with? (Please enter name)\n";
        cin >> name;
        cout << "\nYou have entered " << name << "\n\n";
        if(!pet.chooseAni(name.c_str())) {
          cout << "\nNo pet found with specified name.\n";
          return petMenu();
        }
        pet.chooseAni(name.c_str())->getAni().play();
        cout << "\n";
      break;
      case 6:
        cout << "\nWhich pet do you want to feed? (Please enter name)\n";
        cin >> name;
        cout << "\nYou have entered " << name << "\n\n";
        if(!pet.chooseAni(name.c_str())) {
          cout << "\nNo pet found with specified name.\n";
          return petMenu();
        }
        pet.chooseAni(name.c_str())->getAni().feed();
        cout << "\n";
      break;
      case 0:
        cout << "\nExiting Pet Menu.\n";
        return 1;
      break;
      default:
        cout << "\nInvalid input. Exiting.\n";
        return -1;
      break;
    }
  }
  return petMenu(); // Recursively return until the user enters 0
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
        cout << "\nYou have entered " << name << "\n\n";
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
        cout << "\nYou have entered " << name << "\n\n";
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
  int input = -1; // Menu input
  string name = ""; // Placeholder name for user selecting animals
  string event = ""; // Event to enter for user choice
  CompAnimal tempAnimal;
  while(input != 0) {
    cout << "\nPlease enter one of the following options:\n1. View all competitors\n2. Sign off a competing animal\n" << 
    "3. Sign off all competing animals\n4. Sign up a competing animal\n5. Choose to compete with an animal \n6. View stats of specific animal\n0. Exit\n\n";
    input = getInputChoice(0, 6);
    switch(input) {
      case 1:
        cout << comp;
      break;
      case 2:
        cout << "\nPlease enter the name of the animal to remove:\n";
        cin >> name;
        comp.remove(name.c_str());
        cout << "\n";
      break;
      case 3:
        comp.removeAll();
        cout << "\nAll competitors removed.\n";
      break;
      case 4:
        cin >> tempAnimal;
        comp.insert(tempAnimal);
        cout << tempAnimal;
      break;
      case 5:
        cout << "\nEnter an animal you would like to compete with:\n";
        cin >> name;
        cout << "\nYou have entered " << name << "\n\n";
        if(!comp.chooseAni(name.c_str())) {
          cout << "\nNo animal found with specified name.\n";
          return compMenu();
        }
        cout << "\nPlease enter a name of an event to compete in.\n";
        cin >> event;
        comp.chooseAni(name.c_str())->getAni().competeInEvent(event);
        cout << "\n";
      break;
      case 6:
        cout << "\nWhich animal would you like to check the stats of? (Please enter name)\n";
        cin >> name;
        cout << "\nYou have entered " << name << "\n\n";
        if(!comp.chooseAni(name.c_str())) {
          cout << "\nNo animal found with specified name.\n";
          return compMenu();
        }
        comp.chooseAni(name.c_str())->getAni().checkStats();
        cout << "\n";
      break;
      case 0:
        cout << "\nExiting Competition Menu.\n";
        return 1;
      break;
      default:
        cout << "\nInvalid input. Exiting.\n";
        return -1;
      break;
    }
  }
  return compMenu(); // Recursively return until the user enters 0
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
