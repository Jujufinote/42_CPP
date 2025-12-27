#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP

# include <iostream>

class Example
{
	private :

	public :
		Example(void); // canonical
		Example(Example const& copy); // canonical
		virtual ~Example(void); // canonical

		Example	&operator=(Example const& other); // canonical
};

//std::ostream&	operator<<(std::ostream& o, Example const& other);

#endif
