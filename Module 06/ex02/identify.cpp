#include "header.hpp"

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "Type is A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "Type is B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "Type is C" << std::endl;
	}
	return ;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
		return ;
	}
	catch (...) {} // ... <=> catch all

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		return ;
	}
	catch (...) {}

	return ;
}
