#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
	
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& copy);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& other);

		std::string	target;


	public :

		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
	
		void		execute(Bureaucrat const& executor) const;
};

#endif
