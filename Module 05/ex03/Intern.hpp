#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private :

	public :
		Intern(void);
		Intern(Intern const& copy);
		~Intern(void);

		AForm*	makeForm(std::string const& name_form, std::string const& target);

		Intern&	operator=(Intern const& other);
};

#endif
