#include "header.hpp"

HumanB::HumanB(std::string const &name)
{
	this->name = name;
	this->weapon = NULL;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	return ;
}

void	HumanB::attack(void) const
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " attacks with nothing but its limbs" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
	return ;
}
