#include "header.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "Some WrongAnimal";
	std::cout << "WrongAnimal created" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	*this = copy;
	std::cout << "WrongAnimal copied" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed" << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return ("Type is " + this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some animal made a sound" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this = other);
}
