#include "Ice.hpp"

Ice::Ice(void)
{
	this->type = "ice";
	std::cout << "Ice constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
	this->type = "ice";
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

AMateria	*Ice::clone(void) const
{
	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

Ice	&Ice::operator=(Ice const &other)
{
	AMateria::operator=(other);
	std::cout << "Ice copy assignement operator called" << std::endl;
	return (*this);
}
