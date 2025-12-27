#include "header.hpp"

Animal::Animal(void)
{
	this->type = "Some Animal";
	std::cout << "Animal created" << std::endl;
	return ;
}

Animal::Animal(Animal const &copy)
{
	this->type = copy.type;
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

Animal	&Animal::operator=(Animal const &other)
{
	this->type = other.type;
	std::cout << "Copy assignement operator (Animal) called" << std::endl;
	return (*this);
}
