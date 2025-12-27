#include "header.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "Anonym";
	this->health = 10;
	this->max_health = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "Anonym ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
{
	this->name = name;
	this->health = 10;
	this->max_health = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	this->name = copy.name;
	this->health = copy.health;
	this->max_health = copy.max_health;
	this->energy = copy.energy;
	this->damage = copy.damage;
	std::cout << "ClapTrap " << copy.name << " copyed" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destoyed" << std::endl;
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->health == 0)
	{
		std::cout << this->name << " is dead" << std::endl;
		std::cout << "(No action taken)\n" << std::endl;
		return ;
	}
	if (this->energy == 0)
	{
		std::cout << this->name << " doesn't have enough energy left to take action" << std::endl;
		std::cout << "(Have not attacked)\n" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks " << target;
	std::cout << " causing " << this->damage << " points of damage!" << std::endl;
	this->energy = this->energy - 1;
	std::cout << "(-1 energy,  remaining : " << this->energy << ")\n" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health == 0)
	{
		std::cout << this->name << " is already dead\n" << std::endl;
		return ;
	}
	this->health = this->health - amount;
	if (this->health < 0)
	{
		this->health = 0;
	}
	std::cout << this->name << " took " << amount << " damage" << std::endl;
	if (this->health == 0)
	{
		std::cout << this->name << " died\n" << std::endl;
	}
	else
	{
		std::cout << "(Remaining health : " << this->health << ")\n" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->health == 0)
	{
		std::cout << this->name << " is dead" << std::endl;
		std::cout << "(No action taken)\n" << std::endl;
		return ;
	}
	if (this->energy == 0)
	{
		std::cout << this->name << " doesn't have enough energy left to take action" << std::endl;
		std::cout << "(Health still at " << this->health << ")\n" << std::endl;
		return ;
	}
	if (this->health == this->max_health)
	{
		std::cout << this->name << " is already full heath" << std::endl;
		std::cout << "(No action taken)\n" << std::endl;
		return ;
	}
	this->health = this->health + amount;
	if (this->health > this->max_health)
	{
		std::cout << "Power of repair is " << amount << ", but health maxed out at " << this->max_health << std::endl;
		amount -= this->health - this->max_health;
		this->health = this->max_health;
	}
	std::cout << this->name << " repaired himself by " << amount << " health" << std::endl;
	std::cout << "It has now " << this->health << " health" << std::endl;
	this->energy = this->energy - 1;
	std::cout << "(-1 energy,  remaining : " << this->energy << ")\n" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->name = other.name;
	this->health = other.health;
	this->max_health = other.max_health;
	this->energy = other.energy;
	this->damage = other.damage;
	return (*this);
}
