#include "Animals.h"
#include "DLL.h"


int main() {

  string input = "-1";

  /* DLL<Animal> *animals = new DLL<Animal>;


  animals->addAnimal(new Animal);
  animals->addAnimal(new Animal);
  animals->display(); */

  /* Animal anAni;
  
  Node<Animal>* aNode = new Node<Animal>(Animal(1, animalType::Dog, "john"));

  cout << aNode->getAni();

  delete aNode; */

  //Node<Animal>* aNode = new Node<Animal>(Animal(1, animalType::Dog, "john"));
  //cout << "Display: " << aNode->getAni() << "\n";

  char* test1 = new char[5];
  strcpy(test1, "test");
  string test2 = test1;
  cout << test2 << "<<<<<\n";

  DLL<Animal> animals;
  animals.insert(Animal(1, animalType::Dog, "john"));
  animals.insert(Animal(1, animalType::Dog, "will"));
  animals.insert(Animal(1, animalType::Dog, "will"));
  animals.insert(Animal(1, animalType::Dog, "will"));
  animals.insert(Animal(1, animalType::Dog, "smith"));
  animals.remove("test");
  animals.display();


  cout << "Please enter the type of animal relationship:\n";

  while((input != "1") && (input != "2") && (input != "3") && (input != "0"))
  {
    cout << "Please enter one of the correct following options.\n\n";
    cout << "1. A pet animal\n";
    cout << "2. A service animal\n";
    cout << "3. A competing animal\n";

    cin >> input;
  }

  //if input(1) petMenu

  /* 1. Add pet 2. Remove pet 3. Display all pets 4. Walk pet (increases hours walked) ( += will help this) 5. Compare pets ( <= == >= most hours walked) */
  
  //if input(2) serviceMenu

  /* 1. Add service animal 2. Remove service animal 3. Display all service animals 4.  */

  //if input(3) competeMenu

  /* 1. Add competing animal 2. Remove competing animal 3. Display all competing animals 4. Go to event with animal 5. Compare competing animals ( <= == >= most trophies win/lost ratio) */

  Animal anAnimal;
  cout << anAnimal;
  cin >> anAnimal;
  cout << anAnimal;


  //delete animals;

}


