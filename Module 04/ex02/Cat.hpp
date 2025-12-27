#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
	
		Brain	*mind;

	public:

		Cat(void);
		Cat(Cat const &copy);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
		void			think(std::string thought);

		Brain const		*getBrain(void) const;
		void			readMind(void) const;

		Cat				&operator=(Cat const &other);
};

#endif
