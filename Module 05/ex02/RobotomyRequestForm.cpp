#include "RobotomyRequestForm.hpp"

/*RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
	this->target = "Anonymous";
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return ;
}*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyPardonForm", 72, 45)
{
	this->target = target;
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	return ;
}

/*RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy) : AForm(copy)
{
	this->target = copy.target;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return ;
}*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return;
}

/*---------------------------------------------------------------------------------------------------------------*/

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cerr << "RobotomyRequestForm is not signed, therefore cannot be executed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getReqGradeExe())
		throw GradeTooLowException();
	std::cout << "Starting Robotomy...\n 50% chances of success" << std::endl;
	std::cout << "Some drilling noises...\n DDDRRRRRRRRRRRRRRRRrrrrr" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		std::cout << this->target << " has been successfully robotomized" << std::endl;
	}
	else
	{
		std::cout << "The robotomy tried on " << this->target << " has failed" << std::endl;
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

/*RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	AForm::operator=(other);
	this->target = other.target;
	std::cout << "RobotomyRequestForm copy assignement operator called" << std::endl;
	return (*this);
}*/
