#include "header.hpp"

int main()
{
	/*------------ Test Abstract class -----------*/

	std::cout << std::endl;

		//const Animal no;  // erase com to test instance
		const	Animal* a = new Cat();
		const	Animal* b = new Dog();

	std::cout << std::endl;

		a->makeSound();
		b->makeSound();

	std::cout << std::endl;

		delete a;
		delete b;

	std::cout << std::endl;

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

	return 0;
}
