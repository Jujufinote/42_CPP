#include "header.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
 		zombie[i].put_name(name); //modify put_name(name + std::to_string(i)) to debug
	}
	return zombie;
}
