#include "header.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie has been allocated ^_^" << std::endl;
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

void	Zombie::put_name(std::string name)
{
	this->name = name;
	return ;
}
