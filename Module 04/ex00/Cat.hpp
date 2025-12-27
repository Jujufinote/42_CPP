#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
	
	public:

		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);

		virtual void	makeSound(void) const;

		Cat				&operator=(Cat const &other);
};

#endif
