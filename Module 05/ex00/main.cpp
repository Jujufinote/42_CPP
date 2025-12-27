#include "header.hpp"

int	main(void)
{
	/*-------------- Initializations --------------*/

				std::cout << std::endl;

	try
	{
		std::cout << "TOO HIGH GRADE :" << std::endl;
		Bureaucrat toomuch("Exeeding", 0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	try
	{
		std::cout << "TOO LOW GRADE :" << std::endl;
		Bureaucrat toolow("Deficiency", 151);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	try
	{
		std::cout << "NORMAL :" << std::endl;
		Bureaucrat one("Pablo", 1);
		Bureaucrat two("Pablo2", 150);
	
				std::cout << std::endl;
	
		std::cout << one << std::endl;
		std::cout << two << std::endl;

				std::cout << std::endl;

	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	/*---------- Test pomotion/demotion ----------*/

				std::cout << std::endl;

	Bureaucrat first("Bernard", 1);
	Bureaucrat second("Bernard2", 150);

				std::cout << std::endl;

	std::cout << first << std::endl;
	std::cout << second << std::endl;

				std::cout << std::endl;

	try
	{
		std::cout << "Test promotion :" << std::endl;
		first.incrementGrade();
		std::cout << first << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test demotion :" << std::endl;
		first.decrementGrade();
		std::cout << first << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;
	
	try
	{
		std::cout << "Test demotion :" << std::endl;
		second.decrementGrade();
		std::cout << second << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test promotion :" << std::endl;
		second.incrementGrade();
		std::cout << second << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

				std::cout << std::endl;

	/*---------------- Test copies ----------------*/
/*
				std::cout << std::endl;

	Bureaucrat two(second);

				std::cout << std::endl;

	std::cout << two << std::endl;

				std::cout << std::endl;

	second = first;
	std::cout << second << std::endl;

				std::cout << std::endl;
*/
	//destructors
	return 0;
}
