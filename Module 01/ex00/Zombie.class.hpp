#ifndef ZOMBIE_HPP
# define ZONBIE_HPP

# include <string>

class Zombie
{
	private :
		std::string	name;
	
	public :
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

#endif
