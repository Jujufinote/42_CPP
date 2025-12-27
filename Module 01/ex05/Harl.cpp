#include "header.hpp"

Harl::Harl(void)
{
	ptrDebug = &Harl::debug;
	ptrInfo = &Harl::info;
	ptrWarning = &Harl::warning;
	ptrError = &Harl::error;
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	switch (level[0])
	{
		case ('D') :
		{
			(this->*ptrDebug)();
			break;
		}
		case ('I') :
		{
			(this->*ptrInfo)();
			break;
		}
		case ('W') :
		{
			(this->*ptrWarning)();
			break ;
		}
		case ('E') :
		{
			(this->*ptrError)();
			break;
		}
		default :
			break;
	}
	return ;
}
