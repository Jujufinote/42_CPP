#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const& copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

AForm*	Intern::makeForm(std::string const& name_form, std::string const& target)
{
	AForm*	ptr = NULL;

	std::string names[3] = {"shrubbery request", "robotomy request", "presidential request"};
	int i = 0;

	for (i; i < 3; i++)
	{
		if (names[i] == name_form)
			break;
	}

	switch (i)
	{
		case 0:
		{
			std::cout << "Intern creates " << name_form << std::endl;
			ptr = new ShrubberyCreationForm(target);
			break;
		}

		case 1:
		{
			std::cout << "Intern creates " << name_form << std::endl;
			ptr = new RobotomyRequestForm(target);
			break;
		}

		case 2:
		{
			std::cout << "Intern creates " << name_form << std::endl;
			ptr = new PresidentialPardonForm(target);
			break;
		}
		
		default:
		{
			std::cerr << "The form requested do not exist" << std::endl;
			break;
		}
	}
	return ptr;
}

/*---------------------------------------------------------------------------------------------------------------*/

Intern&	Intern::operator=(Intern const& other)
{
	std::cout << "Intern copy assignement operator called" << std::endl;
	return (*this);
}
