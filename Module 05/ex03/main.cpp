#include "header.hpp"

int	main(void)
{
	/*-------------- Initializations --------------*/

				std::cout << std::endl;

	//AForm one; //test abstract class
	Intern	random;
	Bureaucrat	level2("Charles", 1);

				std::cout << std::endl;

	AForm*	s = random.makeForm("shrubbery request", "Bob");
	AForm*	r = random.makeForm("robotomy request", "Bob");
	AForm*	p = random.makeForm("presidential request", "Bob");
	AForm*	e = random.makeForm("", "Bob");

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
