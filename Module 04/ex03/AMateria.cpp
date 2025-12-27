#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "AMateria " << this->type << " constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &copy)
{
	this->type = copy.type;
	std::cout << "AMateria " << this->type << " copy constructor called" << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria " << this->type << " destructor called" << std::endl;
	return ;
}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	this->type = other.type;
	std::cout << "AMateria " << this->type << " copy assignement operator called" << std::endl;
	return (*this);
}
