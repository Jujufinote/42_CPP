#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
	
	public :

		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);

		virtual void	makeSound(void) const;

		Dog				&operator=(Dog const &other);
};

#endif
