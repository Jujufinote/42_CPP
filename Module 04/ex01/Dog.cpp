#include "header.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->mind = new Brain();
	std::cout << "Dog created" << std::endl;
	return ;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	this->mind = new Brain(*copy.mind);
	std::cout << "Dog copied" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete mind;
	std::cout << "Dog destroyed" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf" << std::endl;
	return ;
}

void	Dog::think(std::string tought)
{
	this->mind->addIdea(tought);
	return ;
}

Brain const	*Dog::getBrain(void) const
{
	return (this->mind);
}

void	Dog::readMind(void) const
{
	this->mind->display();
	return ;
}

Dog	&Dog::operator=(Dog const &other)
{
	Animal::operator=(other);
	delete this->mind;
	this->mind = new Brain(*other.mind);
	std::cout << "Copy assignement operator (Dog) called" << std::endl;
	return (*this);
}
