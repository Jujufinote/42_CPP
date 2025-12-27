#ifndef GROUND_HPP
# define GROUND_HPP

# include "AMateria.hpp"

class Ground
{
	private :
		static AMateria**	items;
		static int			length;

	public :
		Ground(void);
		Ground(Ground const &copy);
		~Ground(void);

		static void			addItem(AMateria *item);
		static AMateria*	suppItem(std::string type);
		static void			destructor(void);

		Ground&	operator=(Ground const &other);
};

#endif
