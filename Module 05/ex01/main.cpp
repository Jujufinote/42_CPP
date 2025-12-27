#include "header.hpp"

int	main(void)
{
	/*-------------- Initializations --------------*/

				std::cout << std::endl;

	try
	{
		std::cout << "TOO HIGH GRADE SIGN :" << std::endl;
		Form toomuch("Exeeding", 0, 1);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "TOO HIGH GRADE EXE :" << std::endl;
		Form toomuch("Exeeding", 1, 0);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	try
	{
		std::cout << "TOO LOW GRADE SIGN :" << std::endl;
		Form toolow("Deficiency", 151, 150);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "TOO LOW GRADE EXE :" << std::endl;
		Form toolow("Deficiency", 150, 151);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	try
	{
		std::cout << "NORMAL :" << std::endl;
		Form one("Taxes", 150, 150);
		Form two("Shopping", 100, 60);
		Form three("Market", 50, 35);
	
				std::cout << std::endl;
	
		std::cout << one << std::endl;
		std::cout << two << std::endl;
		std::cout << three << std::endl;

				std::cout << std::endl;

	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	/*---------------- Test copies ----------------*/

				std::cout << std::endl;

	Form	first("Taxes", 150, 150);
/*	Form	second(first);

				std::cout << std::endl;

	std::cout << second << std::endl;

				std::cout << std::endl;
*/
	/*---------------- Test signing ----------------*/

				std::cout << std::endl;

	Bureaucrat	pablo("Pablo", 132);
	Form		third("Market", 130, 135);

				std::cout << std::endl;

	std::cout << first << std::endl;
	pablo.signForm(first);
	std::cout << first << std::endl;

				std::cout << std::endl;

	std::cout << third << std::endl;
	pablo.signForm(third);
	std::cout << third << std::endl;

				std::cout << std::endl;

	//destructors
	return 0;
}
