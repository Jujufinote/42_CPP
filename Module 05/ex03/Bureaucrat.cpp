#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Anonymous")
{
	this->_grade = LOWEST_GRADE;
	std::cout << "Bureaucrat Anonymous constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (this->_grade > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < HIGHEST_GRADE)
	throw GradeTooHighException();
	this->_grade--;
	std::cout << "Bureaucrat " << this->_name << " has been promoted" << std::endl;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > LOWEST_GRADE)
	throw GradeTooLowException();
	this->_grade++;
	std::cout << "Bureaucrat " << this->_name << " has been demoted" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() << " because" << std::endl;
		std::cerr << e.what() << '\n';
	}
	return;
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << form.getName() << " hasn't been executed by " << this->_name << ", an error has occured : ";
		std::cerr << e.what() << '\n';
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low");
}

/*---------------------------------------------------------------------------------------------------------------*/

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& other)
{
	this->_grade = other._grade;
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	return (*this);
}

/*---------------------------------------------------------------------------------------------------------------*/

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return o;
}
