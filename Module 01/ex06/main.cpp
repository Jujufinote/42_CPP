#include "header.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cerr << "Usage : ./harlFilter < level >\n\t You must give a level (ERROR, WARNING, INFO or DEBUG)" << std::endl;
		return 1;
	}

	harl.complain(av[1]);

	return 0;
}
