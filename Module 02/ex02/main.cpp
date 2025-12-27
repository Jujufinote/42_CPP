#include "header.hpp"

int main( void )
{

	std::cout << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(2);
	Fixed d(3);
	Fixed e;
	Fixed f(c - d);
	Fixed g(c * d);
	Fixed h(c / c);

	std::cout << std::endl;
	
	e = Fixed(c + d);
	
	std::cout << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	
	std::cout << std::endl;

	std::cout << (c < d) << std::endl; // true
	std::cout << (c <= d) << std::endl; // true
	std::cout << (c > d) << std::endl; // false
	std::cout << (c >= d) << std::endl; // false
	std::cout << (c == d) << std::endl; // false
	std::cout << (c != d) << std::endl; // true

	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl;

	std::cout << Fixed::max( c, d ) << std::endl; // d
	std::cout << Fixed::min( c, d ) << std::endl; // c

	std::cout << std::endl;

	return 0;
}
