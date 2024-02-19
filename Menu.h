/* The UserMenu can essentially replace the main function because all the menu
functionality is definied within this class. There are also exceptions for types
of errors that will be thrown so the user can know what input is wrong and how
to react correctly. */

#ifndef _MENU_H_
#define _MENU_H_

#include"DLL.h"

class AnimalException: public exception {
  public:
    const char *what() const noexcept override;
};

class IntException: public exception {
  public:
    const char *what() const noexcept override;
};

class RangeException: public exception {
  public:
    const char *what() const noexcept override;
};

class PoliceException: public exception {
  public:
    const char *what() const noexcept override;
};

class UserMenu {
  public:
    UserMenu();
    ~UserMenu();
    const int displayMenu(); // Displays initial menu

  private:
    const int getInputChoice(const int minInt, const int maxInt) const; // Gets user input as an integer between a max and minimum value, recursively calls until valid input entered
    const int petMenu(); // Helper function to display the pet menu called by displayMenu
    const int policeMenu(); // Helper function to display the police menu called by displayMenu
    const int compMenu(); // Helper function to display the competition menu called by displayMenu
    const bool initializeMenus(); // This will initialize the Pet menu, Police menu, and Comp menu to all have an initial 5 animals to display and the user can manage.
    DLL<Pet> pet; // Doubly linked list of pets contained by user menu
    DLL<PoliceAnimal> police; // Doubly linked list of police animals contained by user menu
    DLL<CompAnimal> comp; // Doubly linked list of comeptitive animals contained by user menu
    
};


#endif // _MENU_H_
