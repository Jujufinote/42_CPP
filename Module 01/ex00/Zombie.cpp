#include "header.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " has been created ^_^" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " has been destroyed X_X" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
