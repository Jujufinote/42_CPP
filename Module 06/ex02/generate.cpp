# include "header.hpp"

Base*	generate(void)
{
	Base*	ptr = NULL;

	switch (rand() % 3)
	{
		case 0 :
		{
			ptr = new A;
			break ;
		}

		case 1 :
		{
			ptr = new B;
			break ;
		}

		case 2 :
		{
			ptr = new C;
			break ;
		}
	}
	return ptr;
}
