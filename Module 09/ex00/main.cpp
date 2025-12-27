#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Usage : ./btc <input file>" << std::endl;
		return 1;
	}

	std::string		input_name = av[1];
	std::ifstream	ifd(input_name);
	if (!(ifd.is_open()))
	{
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}
	
	BitcoinExchange data;

	std::cout << std::endl;
	
	std::string		line;
	std::getline(ifd, line); // pass first line
	while (1)
	{
		std::getline(ifd, line);
		if (ifd.eof() == true)
			break ;
		data.totalRate(line);
	}
	
	std::cout << std::endl;
	return 0;
}
