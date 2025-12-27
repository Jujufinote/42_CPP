#include "PmergeMe.hpp"

int	is_all_digit(std::string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]) && !std::isspace(str[i]))
			throw std::runtime_error("Error: format");
	}
	return 1;
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "Usage : ./PmergeMe <num1> <...>" << std::endl;
		return 1;
	}

	std::vector<unsigned int>	v;
	std::list<unsigned int>		l;

	try
	{
		for (int i = 1; av[i] != NULL; ++i)
		{
			is_all_digit(av[i]);
			v.push_back(std::atoi(av[i]));
			l.push_back(std::atoi(av[i]));
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	PmergeMe	one(v, l);

	std::cout << one << std::endl;

	return 0;
}
