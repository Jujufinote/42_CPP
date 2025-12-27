#include "header.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	result;
	float	temp;

	result = 0;
	temp = (a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getY());
	std::cout << "Results for " << a.getName() << " and " << b.getName() << " : " << temp << std::endl;
	if ( temp > 0 )
	{
		result += 1;
	}
	else if ( temp < 0 )
	{
		result -= 1;
	}
	temp = (b.getX() - point.getX()) * (c.getY() - point.getY()) - (b.getY() - point.getY()) * (c.getX() - point.getY());
	std::cout << "Results for " << b.getName() << " and " << c.getName() << " : " << temp << std::endl;
	if ( temp > 0 )
	{
		result += 1;
	}
	else if ( temp < 0 )
	{
		result -= 1;
	}
	temp = (c.getX() - point.getX()) * (a.getY() - point.getY()) - (c.getY() - point.getY()) * (a.getX() - point.getY());
	std::cout << "Results for " << c.getName() << " and " << a.getName() << " : " << temp << std::endl;
	if ( temp > 0 )
	{
		result += 1;
	}
	else if ( temp < 0 )
	{
		result -= 1;
	}
	if (result == -3 || result == 3)
	{
		return true;
	}
	return false;
}
