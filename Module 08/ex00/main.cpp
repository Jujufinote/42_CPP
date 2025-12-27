#include "easyfind.hpp"

int main(void)
{

				std::cout << std::endl;

	std::vector<int>	v = {0, 1, 2, 3, 4, 5};
	std::list<int>		l = {6, 7, 8, 9, 10};

	try
	{
		std::cout << "Test vector...";
		std::cout << *(easyfind(v, 2)) << std::endl;
		std::cout << *(easyfind(v, 9)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	try
	{
		std::cout << "Test list...";
		std::cout << *(easyfind(l, 9)) << std::endl;
		std::cout << *(easyfind(l, 2)) << std::endl;

	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
