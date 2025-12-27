#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class AMateria;
class ICharacter;
class Ground;

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Ground.hpp"
# include <iomanip>

class Character : public ICharacter
{
	private:

		std::string	name;
		AMateria	*inventory[4];

	public:

		Character(void);
		Character(std::string const name);
		Character(Character const &copy);
		~Character(void);
		
		std::string const	&getName(void) const;
		void				showInventory(void) const;

		void 				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		Character			&operator=(Character const &other);

};

#endif
