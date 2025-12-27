#include "header.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
	return ;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog copied" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &other)
{
	Animal::operator=(other);
	return (*this);
}
