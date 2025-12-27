#include "header.hpp"

int main()
{
	/*----------- Bad Class implementation -----------*/

	std::cout << std::endl;

	const WrongAnimal*	a = new WrongAnimal();
	const WrongAnimal*	b = new WrongCat();
	
	std::cout << std::endl;

	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	
	std::cout << std::endl;

	a->makeSound(); //will output some animal sound
	b->makeSound(); //will output some animal sound

	delete a;
	delete b;

	/*----------- Good Class implementation -----------*/

	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << std::endl; //dog type
	std::cout << i->getType() << std::endl; //cat type
	
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound
	j->makeSound(); //will output the dog sound
	meta->makeSound(); //will output some animal sound

	delete meta;
	delete j;
	delete i;

	return 0;
}
