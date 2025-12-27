#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected :

		static int const	base_health;
		static int const	base_energy;
		static int const	base_damage;

	
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
 