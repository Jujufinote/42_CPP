#include "PresidentialPardonForm.hpp"

/*PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
	this->target = "Anonymous";
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return ;
}*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	return ;
}

/*PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy) : AForm(copy)
{
	this->target = copy.target;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return ;
}*/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return;
}

/*---------------------------------------------------------------------------------------------------------------*/

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cerr << "PresidentialPardonForm is not signed, therefore cannot be executed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getReqGradeExe())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

/*PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	AForm::operator=(other);
	this->target = other.target;
	std::cout << "PresidentialPardonForm copy assignement operator called" << std::endl;
	return (*this);
}*/
