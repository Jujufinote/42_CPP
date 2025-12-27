#include "header.hpp"

int	main(void)
{
	Zombie	*zombie = zombieHorde(4, "Alberto");

	for (int i = 0; i < 4; i++)
	{
		zombie[i].announce();
	}
	delete []zombie;
	return 0;
}
