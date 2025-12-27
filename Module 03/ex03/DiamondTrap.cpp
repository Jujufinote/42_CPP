#include "header.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = "Anonym";
	this->health = this->base_health;
	this->max_health = this->base_health;
	this->energy = this->base_energy;
	this->damage = this->base_damage;
	std::cout << "Anonym DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->health = this->base_health;
	this->max_health = this->base_health;
	this->energy = this->base_energy;
	this->damage = this->base_damage;
	std::cout << "DiamondTrap " << this->name << " created" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	this->name = copy.name;
	std::cout << "DiamondTrap " << copy.name << " copyed" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " destoyed" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Who am i ? " << this->name << " or " << ClapTrap::name << " ...\n" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
    FragTrap::operator=(other);
    return (*this);
}
