#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class ICharacter;

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:

		std::string	type;
	
	public:

		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
		virtual ~AMateria(void);

		std::string const	&getType(void) const;

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;

		AMateria			&operator=(AMateria const &other);

};

#endif
