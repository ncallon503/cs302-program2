/* Nathan Callon, 2/18/2024, Program #2, CS302, Karla Fant
This program uses a combinaton of templates with doubly linked lists and nodes to manage
animals through a menu system that the client can access the public methods of. There
are some random numbers that are used to determine actions of events that happen
so there is an initial seed here, and then the menu is simply opened and all
the menu actions are handled from the UserMenu class. */

#include "Animals.h"
#include "DLL.h"
#include "Menu.h"

int main() {

  srand(time(0)); // Seeds random number generator

  UserMenu clientMenu;
  clientMenu.displayMenu();
}


