#include "iter.hpp"

void	toupper_char(char& c)
{
	c = std::toupper(c);
	return ;
}

int main(void)
{
	std::string str = "abcdefghijklmnopqrstuvwxyz";

	iter(&str[0], 26, toupper_char);

	std::cout << str << std::endl;

	return 0;
}
