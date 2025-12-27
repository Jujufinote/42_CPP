#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:

		Brain	*mind;

	public :

		Dog(void);
		Dog(Dog const &copy);
		virtual ~Dog(void);

		virtual void	makeSound(void) const;
		void			think(std::string thought);

		Brain const		*getBrain(void) const;
		void			readMind(void) const;

		Dog				&operator=(Dog const &other);
};

#endif
