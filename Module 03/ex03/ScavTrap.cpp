#include "header.hpp"

int const ScavTrap::base_health = 100;
int const ScavTrap::base_energy = 50;
int const ScavTrap::base_damage = 20;

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->health = this->base_health;
	this->max_health = this->base_health;
	this->energy = this->base_energy;
	this->damage = this->base_damage;
	std::cout << "Anonym ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->health = this->base_health;
	this->max_health = this->base_health;
	this->energy = this->base_energy;
	this->damage = this->base_damage;
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << copy.name << " copyed" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destoyed" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->health == 0)
	{
		std::cout << this->name << " is passed out" << std::endl;
		std::cout << "(No action taken)\n" << std::endl;
		return ;
	}
	if (this->energy == 0)
	{
		std::cout << this->name << " doesn't have enough mana left to cast any action" << std::endl;
		std::cout << "(Have not attacked)\n" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks " << target;
	std::cout << " with fireball causing " << this->damage << " of damage !" << std::endl;
	this->energy = this->energy - 1;
	std::cout << "(-1 energy,  remaining : " << this->energy << ")\n" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode\n" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
    ClapTrap::operator=(other);
	this->max_health = other.max_health;
    return (*this);
}
