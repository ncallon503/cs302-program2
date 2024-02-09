#include "Animals.h"


int main() {

  string input = "-1";

  DLL<Animal> * animals = nullptr;
  animals = new DLL<Animal>();

  animals->addAnimal(new Animal);
  animals->addAnimal(new Animal);
  animals->display();

  cout << "Please enter the type of animal relationship:\n";

  while((input != "1") && (input != "2") && (input != "3") && (input != "0"))
  {
    cout << "Please enter one of the correct following options.\n\n";
    cout << "1. A pet animal\n";
    cout << "2. A service animal\n";
    cout << "3. A competing animal\n";

    cin >> input;
  }

  delete animals;

}


