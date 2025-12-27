#include "header.hpp"

Animal::Animal(void)
{
	this->type = "Some Animal";
	std::cout << "Animal created" << std::endl;
	return ;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << "Animal copied" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroyed" << std::endl;
	return ;
}

std::string	Animal::getType(void) const
{
	return ("Type is " + this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Some animal made a sound" << std::endl;
	return ;
}

Animal	&Animal::operator=(Animal const &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this = other);
}
