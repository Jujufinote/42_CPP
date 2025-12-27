#include "header.hpp"

int	main(void)
{
	std::cout << std::endl;
	Zombie *zombie = newZombie("Roberto");

	zombie->announce();
	delete zombie;
	std::cout << std::endl;
	randomChump("Equipedia");
	return 0;
}
