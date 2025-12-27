#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{
	private :

		int					value;
		static int const	bits;


	public :

		Fixed(void);
		Fixed( Fixed const &copy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed	&operator=(Fixed const &other);
};

#endif
