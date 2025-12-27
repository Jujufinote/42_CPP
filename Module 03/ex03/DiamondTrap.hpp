#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private :

		std::string name;
		using FragTrap::base_health;
		using ScavTrap::base_energy;
		using FragTrap::base_damage;

	public :

		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap(void);

		void	whoAmI(void);
		using	ScavTrap::attack;

		DiamondTrap	&operator=(DiamondTrap const &other);

};

#endif
