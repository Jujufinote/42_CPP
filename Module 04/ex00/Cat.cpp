#include "header.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
	return ;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout << "Cat copied" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destroyed" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &other)
{
	Animal::operator=(other);
	return (*this = other);
}
