#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
	
	public:

		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);

		AMateria*	clone() const;
		void		use(ICharacter &target);

		Ice			&operator=(Ice const &other);

};

#endif
