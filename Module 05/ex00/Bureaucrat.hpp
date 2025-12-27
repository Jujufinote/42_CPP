#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Bureaucrat
{
	private :
	
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& copy);
		Bureaucrat&	operator=(Bureaucrat const&	other);

		const std::string	_name;
		int					_grade;


	public :

		Bureaucrat(const std::string name, int grade);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

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

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& other);

#endif
