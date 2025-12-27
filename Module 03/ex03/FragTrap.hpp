#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected :

		static int const	base_health;
		static int const	base_energy;
		static int const	base_damage;


	public :

		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &copy);
		~FragTrap(void);

		void	highFivesGuys(void);

		FragTrap	&operator=(FragTrap const &other);

};

#endif
