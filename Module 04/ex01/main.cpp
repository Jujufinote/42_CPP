#include "header.hpp"

int main()
{
	/*--------------- Tests copies ---------------*/

	std::cout << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	((Dog *)j)->think("Play");
	((Dog *)i)->think("Dominance");
	((Dog *)i)->think("Disdain");

	std::cout << std::endl;

	//copies
	const Animal* j_copy = new Dog(*(Dog *)j);
	const Animal* i_copy = new Cat(*(Cat *)i);

	std::cout << std::endl;

		//same brain dog
	std::cout << ((Dog *)j)->getBrain() << std::endl;
	std::cout << ((Dog *)j_copy)->getBrain() << std::endl;
	((Dog *)j)->readMind();
	((Dog *)j_copy)->readMind();
	
	std::cout << std::endl;
	std::cout << std::endl;

		//same brain cat
	std::cout << ((Cat *)i)->getBrain() << std::endl;
	std::cout << ((Cat *)i_copy)->getBrain() << std::endl;
	((Cat *)i)->readMind();
	((Cat *)i_copy)->readMind();

	std::cout << std::endl;

	delete j;
	delete i;

	/*--------------- Tests table ---------------*/

/* The goal here is to create a table
  of  animal pointers (parent) and fill it with
  cats and dogs (child), we must be capable of 
  delete all animals without leak.
  To do so we need to first delete children, BUT we are
  "in an animal", the "view" is on the parent,
  if we try to delete without any change, 
  children will not be deleted and will leak.
  Therefore, we change normal destructor in virtual
  for it to go execute himself at the furthest children
  and then it will climb up to the parent */

 	std::cout << std::endl;

	const Animal* meta[4];

	for (int i = 0; i < 2; ++i) // fill with dogs
	{
		meta[i] = new Dog();
	}
	for (int i = 2; i < 4; ++i) // fill with cats
	{
		meta[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; ++i) // delete table
	{
		delete meta[i];
	}

	return 0;
}
