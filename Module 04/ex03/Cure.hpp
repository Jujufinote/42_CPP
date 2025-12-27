#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
	
	public:

		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);

		AMateria*	clone() const;
		void		use(ICharacter &target);

		Cure		&operator=(Cure const &other);

};

#endif
