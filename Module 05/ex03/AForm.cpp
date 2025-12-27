#include "AForm.hpp"

AForm::AForm(void) : _name("Anonymous"), _is_signed(false), _req_grade_sign(1), _req_grade_exe(1)
{
	std::cout << "AForm anonymous constructor called" << std::endl;
	return;
}

AForm::AForm(std::string const name, int const req_grade_sign, int const req_grade_exe) : _name(name), _is_signed(false), _req_grade_sign(req_grade_sign), _req_grade_exe(req_grade_exe)
{
	if (req_grade_exe < HIGHEST_GRADE || req_grade_sign < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (req_grade_exe > LOWEST_GRADE || req_grade_sign > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
	return ;
}

AForm::AForm(AForm const& copy) : _name(copy._name), _is_signed(copy._is_signed), _req_grade_sign(copy._req_grade_sign), _req_grade_exe(copy._req_grade_exe)
{
	std::cout << "AForm copy constructor called" << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

int const	AForm::getReqGradeSign(void) const
{
	return (this->_req_grade_sign);
}

int const	AForm::getReqGradeExe(void) const
{
	return (this->_req_grade_exe);
}

/*---------------------------------------------------------------------------------------------------------------*/

void	AForm::beSigned(Bureaucrat const& by)
{
	if (by.getGrade() > this->_req_grade_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low");
}

/*---------------------------------------------------------------------------------------------------------------*/

AForm&	AForm::operator=(AForm const& other)
{
	this->_is_signed = other.getIsSigned();
	std::cout << "AForm copy assignement operator called" << std::endl;
	return (*this);
}

/*---------------------------------------------------------------------------------------------------------------*/

std::ostream&	operator<<(std::ostream& o, AForm const& other)
{
	o << "The form " << other.getName();
	if (other.getIsSigned() == true)
		std::cout << " is signed, ";
	else
		std::cout << " is not signed, ";
	std::cout << " requires grade " << other.getReqGradeSign() << " to be signed ";
	std::cout << " and grade " << other.getReqGradeExe() << " to be executed" << std::endl;
	return o;
}
