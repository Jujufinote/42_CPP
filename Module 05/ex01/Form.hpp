#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include <iostream>
# include "Bureaucrat.hpp"

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Form
{
	private :
	
		Form(void);
		Form(Form const& copy);
		Form&	operator=(Form const& other);

		std::string const	_name;
		bool				_is_signed;
		int const			_req_grade_sign;
		int const			_req_grade_exe;


	public :

		Form(std::string const name, int const req_grade_sign, int const req_grade_exe);
		~Form(void);

		std::string const	getName(void) const;
		bool				getIsSigned(void) const;
		int const			getReqGradeSign(void) const;
		int const			getReqGradeExe(void) const;

		void				beSigned(Bureaucrat const& by);

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

std::ostream&	operator<<(std::ostream& o, Form const& other);

#endif
