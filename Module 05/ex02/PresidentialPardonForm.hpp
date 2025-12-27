#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :

		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& copy);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& other);

		std::string	target;

		
	public :

		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
	
		void		execute(Bureaucrat const& executor) const;
};

#endif
