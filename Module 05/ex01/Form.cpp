#include "Form.hpp"

Form::Form(void) : _name("Anonymous"), _is_signed(false), _req_grade_sign(1), _req_grade_exe(1)
{
	std::cout << "Form anonymous constructor called" << std::endl;
	return;
}

Form::Form(std::string const name, int const req_grade_sign, int const req_grade_exe) : _name(name), _is_signed(false), _req_grade_sign(req_grade_sign), _req_grade_exe(req_grade_exe)
{
	if (req_grade_exe < HIGHEST_GRADE || req_grade_sign < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (req_grade_exe > LOWEST_GRADE || req_grade_sign > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
	return ;
}

Form::Form(Form const& copy) : _name(copy._name), _is_signed(copy._is_signed), _req_grade_sign(copy._req_grade_sign), _req_grade_exe(copy._req_grade_exe)
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int const	Form::getReqGradeSign(void) const
{
	return (this->_req_grade_sign);
}

int const	Form::getReqGradeExe(void) const
{
	return (this->_req_grade_exe);
}

/*---------------------------------------------------------------------------------------------------------------*/

void	Form::beSigned(Bureaucrat const& by)
{
	if (by.getGrade() > this->_req_grade_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low");
}

/*---------------------------------------------------------------------------------------------------------------*/

Form&	Form::operator=(Form const& other)
{
	this->_is_signed = other.getIsSigned();
	std::cout << "Form copy assignement operator called" << std::endl;
	return (*this);
}

/*---------------------------------------------------------------------------------------------------------------*/

std::ostream&	operator<<(std::ostream& o, Form const& other)
{
	o << "The form " << other.getName();
	if (other.getIsSigned() == true)
		o << " is signed, ";
	else
		o << " is not signed, ";
	o << " requires grade " << other.getReqGradeSign() << " to be signed ";
	o << " and grade " << other.getReqGradeExe() << " to be executed" << std::endl;
	return o;
}
