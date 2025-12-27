#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :

	public :

		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap(void);

		void	attack(std::string const &target);
		void	guardGate(void);

		ScavTrap	&operator=(ScavTrap const &other);

};

#endif
 