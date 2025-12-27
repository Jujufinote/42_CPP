#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private :
	
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& copy);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& other);

		std::string	target;


	public :

		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
	
		void		execute(Bureaucrat const& executor) const;
};

#endif
