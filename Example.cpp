#include "Example.hpp"

Example::Example(void)
{
	std::cout << "Example default constructor called" << std::endl;
	return ;
}

Example::Example(Example const& copy)
{
	std::cout << "Example copy constructor called" << std::endl;
	return ;
}

Example::~Example(void)
{
	std::cout << "Example destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

Example&	Example::operator=(Example const& other)
{
	std::cout << "Example copy assignement operator called" << std::endl;
	return (*this);
}
