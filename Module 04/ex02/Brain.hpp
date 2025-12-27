#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	private :

		std::string	ideas[100];

	public :

		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);

		void	addIdea(std::string const idea);

		void	display(void) const;

		Brain	&operator=(Brain const &other);

};

#endif
