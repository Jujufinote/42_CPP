#include "header.hpp"

Weapon::Weapon(void)
{
	this->type = "nothing";
	return ;
}

Weapon::Weapon(std::string const &type)
{
	this->type = type;
	return ;
}

void	Weapon::setType(std::string const &newtype)
{
	this->type = newtype;
	return ;
}

const std::string	&Weapon::getType(void)const
{
	const std::string	&ref = this->type;

	return ref;
}
