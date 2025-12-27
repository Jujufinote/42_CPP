#include "header.hpp"

int	main(void)
{
	/*-------------- Initializations --------------*/

				std::cout << std::endl;

	//AForm one; //test abstract class
	AForm*	s = new ShrubberyCreationForm("Home");
	AForm*	r = new RobotomyRequestForm("Guinea Pig");
	AForm*	p = new PresidentialPardonForm("Minister");
	Bureaucrat	level0("David", 130);
	Bureaucrat	level1("Hector", 30);
	Bureaucrat	level2("Charles", 1);

				std::cout << std::endl;

	/*----------- Tests form executions -----------*/

				std::cout << std::endl;

	//tests form not signed
	level2.executeForm(*s);
	level2.executeForm(*r);
	level2.executeForm(*p);

				std::cout << std::endl;

	level2.signForm(*s);
	level2.signForm(*r);
	level2.signForm(*p);

				std::cout << std::endl;

	//tests forms signed
	level0.executeForm(*s);
	level0.executeForm(*r);
	level0.executeForm(*p);

				std::cout << std::endl;

	level1.executeForm(*s);
	level1.executeForm(*r);
	level1.executeForm(*p);

				std::cout << std::endl;

	level2.executeForm(*s);
	level2.executeForm(*r);
	level2.executeForm(*p);

				std::cout << std::endl;

	//destructors
	delete s;
	delete r;
	delete p;
	
	return 0;
}
