#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <string>

class Harl
{
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		void	(Harl::*ptrDebug)(void);
		void	(Harl::*ptrInfo)(void);
		void	(Harl::*ptrWarning)(void);
		void	(Harl::*ptrError)(void);

	public :
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
