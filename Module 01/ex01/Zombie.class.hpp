#ifndef ZOMBIE_HPP
# define ZONBIE_HPP

# include <string>

class Zombie
{
	private :
		std::string	name;
	
	public :
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void put_name(std::string name);
};

#endif
