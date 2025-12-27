#include "Cure.hpp"

Cure::Cure(void) : AMateria()
{
	this->type = "cure";
	std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
	this->type = "cure";
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

AMateria	*Cure::clone(void) const
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}

Cure	&Cure::operator=(Cure const &other)
{
	AMateria::operator=(other);
	std::cout << "Cure copy assignement operator called" << std::endl;
	return (*this);
}
