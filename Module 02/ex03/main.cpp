#include "header.hpp"

int main( void )
{
	/*------------- Tests default -------------*/
	
	std::cout << std::endl;
	
	Point	dflt;
	
	std::cout << std::endl;

	std::cout << "Name " << dflt.getName() << std::endl;
	std::cout << "X : " << dflt.getX() << std::endl;
	std::cout << "Y : " << dflt.getY() << std::endl;
	
	std::cout << std::endl;

	/*--- Tests constructors with parameters----*/

	std::cout << std::endl;

	Point	a("A", 0, 0);
	Point	b("B", 0, 3);
	Point	c("C", 3, 0);
	Point	p("P", 1 , 1);
	Point	p2("P2", 1.5 , 1.5);
	Point	p3("P3", 2 , 2);

	std::cout << std::endl;

	std::cout << "Name " << p2.getName() << std::endl;
	std::cout << "X : " << p2.getX() << std::endl;
	std::cout << "Y : " << p2.getY() << std::endl;

	std::cout << std::endl;

	/*------------- Tests copies --------------*/

	std::cout << std::endl;

	Point	p2_copy(p2);

	std::cout << std::endl;

	std::cout << "Name " << p2_copy.getName() << std::endl;
	std::cout << "X : " << p2_copy.getX() << std::endl;
	std::cout << "Y : " << p2_copy.getY() << std::endl;

	std::cout << std::endl;

	/*--------------- Tests bsp ---------------*/

	std::cout << std::endl;


	if (bsp(a, b, c, p) == true)
	{
		std::cout << "The point " << p.getName() << " is in the triangle " << a.getName() << b.getName() << c.getName() << std::endl;
	}
	else
	{
		std::cout << "The point " << p.getName() << " isn\'t in the triangle " << a.getName() << b.getName() << c.getName() << std::endl;
	}


	std::cout << std::endl;


	if (bsp(a, b, c, p2) == true)
	{
		std::cout << "The point " << p2.getName() << " is in the triangle " << a.getName() << b.getName() << c.getName() << std::endl;
	}
	else
	{
		std::cout << "The point " << p2.getName() << " isn\'t in the triangle " << a.getName() << b.getName() << c.getName() << std::endl;
	}


	std::cout << std::endl;


	if (bsp(a, b, c, p3) == true)
	{
		std::cout << "The point " << p3.getName() << " is in the triangle " << a.getName() << b.getName() << c.getName() << std::endl;
	}
	else
	{
		std::cout << "The point " << p3.getName() << " isn\'t in the triangle " << a.getName() << b.getName() << c.getName() << std::endl;
	}


	std::cout << std::endl;
	std::cout << std::endl;

	//destructors

	return 0;
}
