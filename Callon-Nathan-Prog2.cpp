#include "Animals.h"
#include "DLL.h"
#include "Menu.h"

int main() {

  srand(time(0)); // Seeds random number generator

  /* string input = "-1";

  PoliceAnimal anAnimal1; // const int anAge, const policeType aPType, const string aName, const int theHoursServed, const int theMissionsCompleted, const int theMissionsFailed
  PoliceAnimal anAnimal2(10, policeType::Bomb, "doggo", 5, 10, 3);
  PoliceAnimal anAnimal3(anAnimal2);
  anAnimal3.goOnMission();
  anAnimal3.switchRole(policeType::Cadaver);
  cout << anAnimal2;
  cout << anAnimal3;

  cin >> anAnimal1;

  cout << "An animal 1: " << anAnimal1 << "\n\n"; */

  UserMenu clientMenu;
  clientMenu.displayMenu();

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

  /* DLL<Animal> animals;
  cin >> animals;
  cin >> animals;
  cin >> animals;
  cin >> animals;
  cin >> animals;
  animals.display();
  animals.display();
  animals.display();
  animals.display();
  animals.insert(Animal(1, animalType::Dog, "john"));
  animals.insert(Animal(1, animalType::Dog, "will"));
  animals.insert(Animal(1, animalType::Dog, "will"));
  animals.insert(Animal(1, animalType::Dog, "will"));
  animals.insert(Animal(1, animalType::Dog, "smith"));
  animals.chooseAni("john")->getAni().testFun(123123);
  DLL<Test> tests;
  tests.insert(Test());
  tests.chooseAni("123")->getAni().testingThis();
  animals.remove("test");
  animals.display(); */

  //if input(1) petMenu

  /* 1. Add pet 2. Remove pet 3. Display all pets 4. Walk pet (increases hours walked) ( += will help this) 5. Compare pets ( <= == >= most hours walked) */
  
  //if input(2) serviceMenu

  /* 1. Add service animal 2. Remove service animal 3. Display all service animals 4.  */

  //if input(3) competeMenu

  /* 1. Add competing animal 2. Remove competing animal 3. Display all competing animals 4. Go to event with animal 5. Compare competing animals ( <= == >= most trophies win/lost ratio) */

  // Animal anAnimal;
  // cout << anAnimal;
  // cin >> anAnimal;
  // cout << anAnimal;


  //delete animals;

}


