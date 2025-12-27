#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
	private :

		int					value;
		static int const	bits;


	public :

		Fixed(void);
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed( Fixed const &copy);
		~Fixed(void);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		
		int				toInt(void) const;
		float			toFloat(void) const;
	
		Fixed			&operator=(Fixed const &other);
	};
	
std::ostream			&operator<<(std::ostream &o, Fixed const &other);

#endif
