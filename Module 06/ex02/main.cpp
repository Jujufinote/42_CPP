#include "header.hpp"

int	main(void)
{

	std::cout << std::endl;

	Base*	a = generate();
	Base*	b = generate();
	Base*	c = generate();
	Base*	d = generate();
	Base*	e = generate();
	Base*	f = generate();
	Base*	g = generate();
	Base*	h = generate();
	Base*	i = generate();


	std::cout << std::endl;

	identify(a);
	identify(*a);
	delete a;

	std::cout << std::endl;

	identify(b);
	identify(*b);
	delete b;

	std::cout << std::endl;

	identify(c);
	identify(*c);
	delete c;

	std::cout << std::endl;

	identify(d);
	identify(*d);
	delete d;

	std::cout << std::endl;

	identify(e);
	identify(*e);
	delete e;

	std::cout << std::endl;

	identify(f);
	identify(*f);
	delete f;

	std::cout << std::endl;

	identify(g);
	identify(*g);
	delete g;

	std::cout << std::endl;

	identify(h);
	identify(*h);
	delete h;

	std::cout << std::endl;

	identify(i);
	identify(*i);
	delete i;

	std::cout << std::endl;

	return 0;
}
