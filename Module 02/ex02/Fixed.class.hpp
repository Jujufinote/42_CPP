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
		
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	
		int					toInt(void) const;
		float				toFloat(void) const;
		
		bool				operator>(Fixed const &other) const;
		bool				operator>=(Fixed const &other) const;
		bool				operator<(Fixed const &other) const;
		bool				operator<=(Fixed const &other) const;
		bool				operator==(Fixed const &other) const;
		bool				operator!=(Fixed const &other) const;
		
		Fixed				operator+(Fixed const &other) const;
		Fixed				operator-(Fixed const &other) const;
		Fixed				operator*(Fixed const &other) const;
		Fixed				operator/(Fixed const &other) const;
		
		Fixed				&operator=(Fixed const &other);
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);

};

std::ostream				&operator<<(std::ostream &o, Fixed const &other);

#endif
