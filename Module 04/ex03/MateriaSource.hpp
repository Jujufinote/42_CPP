#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria	*stock[4];

	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);
		~MateriaSource(void);

		void			learnMateria(AMateria *m);
		AMateria*		createMateria(std::string const &type);

		MateriaSource	&operator=(MateriaSource const &other);

};

#endif
