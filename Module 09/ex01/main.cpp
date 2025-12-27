#include "RPN.hpp"

int main(int ac, char** av)
{
	try
	{
		if (ac != 2)
		{
			std::cerr << "Usage : ./RPN \"<mathematical expression in RPN>\"" << std::endl;
			return 1;
		}

		RPN	stock;
		
		std::string	str = av[1];
		for (int i = 0; i < str.length(); ++i)
		{
			if (std::isdigit(str[i]) == true)
				stock.addNumber(str[i] - '0');
			else if (str[i] == '*' || str[i] == '-' || str[i] == '+' || str[i] == '/')
				stock.merge(str[i]);
			else if (std::isspace(str[i]) == false)
			{
				std::cerr << "Error : format is not available" << std::endl;
				return 1;
			}
		}

		int	result = stock.getNumber(); // is before 'if' because a pop is in getNumber

		if (stock.getSize() > 0)
		{
			std::cerr << "Error : missing operator(s)" << std::endl;
			return 1;
		}

		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
