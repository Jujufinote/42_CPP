#include "header.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->mind = new Brain();
	std::cout << "Cat created" << std::endl;
	return ;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	this->mind = new Brain(*copy.mind);
	std::cout << "Cat copied" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete mind;
	std::cout << "Cat destroyed" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
	return ;
}

void	Cat::think(std::string tought)
{
	this->mind->addIdea(tought);
	return ;
}

Brain const	*Cat::getBrain(void) const
{
	return (this->mind);
}

void	Cat::readMind(void) const
{
	this->mind->display();
	return ;
}

Cat	&Cat::operator=(Cat const &other)
{
	Animal::operator=(other);
	delete this->mind;
	this->mind = new Brain(*other.mind);
	std::cout << "Copy assignement operator (Cat) called" << std::endl;
	return (*this);
}
