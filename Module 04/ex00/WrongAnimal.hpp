#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected :
	
		std::string	type;


	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &copy);
		~WrongAnimal(void);

		std::string		getType(void) const;

		void	makeSound(void) const;

		WrongAnimal		&operator=(WrongAnimal const &other);

};

#endif
