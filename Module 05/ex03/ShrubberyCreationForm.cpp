#include "ShrubberyCreationForm.hpp"

/*ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
	this->target = "Anonymous";
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

/*ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy) : AForm(copy)
{
	this->target = copy.target;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return ;
}*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return;
}

/*---------------------------------------------------------------------------------------------------------------*/

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cerr << "ShrubberyCreationForm is not signed, therefore cannot be executed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getReqGradeExe())
		throw GradeTooLowException();

	std::ofstream	ofd(this->target + "_shrubbery");
	if (!(ofd.is_open()))
	{
		std::cerr << "Error creating/opening file" << std::endl;
	}
	else
	{
		ofd << "                                                         .\n";
		ofd << "                                              .         ;  \n";
		ofd << "                 .              .              ;%     ;;   \n";
		ofd << "                   ,           ,                :;%  %;   \n";
		ofd << "                    :         ;                   :;%;'     .,   \n";
		ofd << "           ,.        %;     %;            ;        %;'    ,;\n";
		ofd << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
		ofd << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
		ofd << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
		ofd << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
		ofd << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
		ofd << "                    `:%;.  :;bd%;          %;@%;'\n";
		ofd << "                      `@%:.  :;%.         ;@@%;'   \n";
		ofd << "                        `@%.  `;@%.      ;@@%;         \n";
		ofd << "                          `@%%. `@%%    ;@@%;        \n";
		ofd << "                            ;@%. :@%%  %@@%;       \n";
		ofd << "                              %@bd%%%bd%%:;     \n";
		ofd << "                                #@%%%%%:;;\n";
		ofd << "                                %@@%%%::;\n";
		ofd << "                                %@@@%(o);  . '         \n";
		ofd << "                                %@@@o%;:(.,'         \n";
		ofd << "                            `.. %@@@o%::;         \n";
		ofd << "                               `)@@@o%::;         \n";
		ofd << "                                %@@(o)::;        \n";
		ofd << "                               .%@@@@%::;         \n";
		ofd << "                               ;%@@@@%::;.          \n";
		ofd << "                              ;%@@@@%%:;;;. \n";
		ofd << "                          ...;%@@@@@%%:;;;;,..   \n";
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

/*ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	AForm::operator=(other);
	this->target = other.target;
	std::cout << "ShrubberyCreationForm copy assignement operator called" << std::endl;
	return (*this);
}
*/
