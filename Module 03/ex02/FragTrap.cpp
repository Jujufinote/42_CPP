#include "header.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->health = 100;
	this->max_health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "Anonym FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->health = 100;
	this->max_health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " created" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << copy.name << " copyed" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destoyed" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " is now requesting high five to its team : \'Good job teeeaaam ! High Five !\'\n" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
    ClapTrap::operator=(other);
	this->max_health = other.max_health;
    return (*this);
}
