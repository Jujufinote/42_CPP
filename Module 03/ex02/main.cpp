#include "header.hpp"

int	main(void)
{
	FragTrap first("George");
	FragTrap second("Edouard");
	FragTrap third;
	FragTrap fourth(first);

	third = second;

	std::cout << std::endl;

	//Test copies
	third.attack("Leonard");
	fourth.attack("Evelynn");

	std::cout << std::endl;

	//Primary actions
	first.attack("Felipe");
	first.highFivesGuys();
	first.takeDamage(6);
	first.beRepaired(5);

	std::cout << std::endl;

	//Repair full health
	first.beRepaired(5);
	first.beRepaired(5);

	std::cout << std::endl;

	//we clean energy and reduce health
	for (int i = 0; i < 99; ++i)
	{
		third.attack("Leonard");
		third.takeDamage(1);
	}

	std::cout << std::endl;

	//last energy spent, no action taken
	third.beRepaired(10);
	third.attack("Leonard");

	std::cout << std::endl;

	//FragTrap dead
	third.takeDamage(3);

	std::cout << std::endl;

	//No action taken, FragTrap is dead
	third.beRepaired(10);
	third.takeDamage(3);
	third.attack("Leonard");

	return (0);
}
