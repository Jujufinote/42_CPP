#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;

# include <iostream>
# include "Bureaucrat.hpp"

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class AForm
{
	private :
	
		AForm(void);
		AForm(AForm const& copy);
		AForm&	operator=(AForm const& other);

		std::string const	_name;
		bool				_is_signed;
		int const			_req_grade_sign;
		int const			_req_grade_exe;


	public :

		AForm(std::string const name, int const req_grade_sign, int const req_grade_exe);
		virtual ~AForm(void);

		std::string const	getName(void) const;
		bool				getIsSigned(void) const;
		int const			getReqGradeSign(void) const;
		int const			getReqGradeExe(void) const;

		void				beSigned(Bureaucrat const& by);
		virtual void		execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char*	what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, AForm const& other);

#endif
