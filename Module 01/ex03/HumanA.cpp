#include "header.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}
