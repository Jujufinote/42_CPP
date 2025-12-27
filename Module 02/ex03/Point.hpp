#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.class.hpp"

class Point
{
	private:

		std::string name;
		Fixed const	x;
		Fixed const	y;

	public:

		Point(void);
		Point(std::string name, float const x, float const y);
		Point(Point const &copy);
		~Point(void);

		float const			getX(void) const;
		float const			getY(void) const;
		std::string const	getName(void) const;

		Point	&operator=(Point const &other) = delete;
};

#endif
