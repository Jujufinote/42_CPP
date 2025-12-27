#include "header.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copied" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Weom" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	WrongAnimal::operator=(other);
	return (*this = other);
}
