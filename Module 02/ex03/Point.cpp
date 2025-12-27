#include "header.hpp"

Point::Point(void) : x(0), y(0)
{
	this->name = "";
	std::cout << "Point constructor called" << std::endl;
	return ;
}

Point::Point(std::string name, float const x, float const y) : x(x), y(y)
{
	this->name = name;
	std::cout << "Point Float constructor called" << std::endl;
	return ;
}

Point::Point(Point const &copy) : x(copy.x), y(copy.y)
{
	this->name = copy.name;
	std::cout << "Point Copy constructor called" << std::endl;
	return ;
}

Point::~Point(void)
{
	std::cout << "Point destructor called" << std::endl;
	return ;
}

float const	Point::getX(void) const
{
	return (this->x.toFloat());
}

float const	Point::getY(void) const
{
	return (this->y.toFloat());
}

std::string const	Point::getName(void) const
{
	return (this->name);
}
