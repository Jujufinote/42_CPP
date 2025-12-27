#include "header.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);

	std::cout << name << " has been allocated 0_0" << std::endl;
	return zombie;
}
