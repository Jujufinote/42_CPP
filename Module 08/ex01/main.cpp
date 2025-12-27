#include "Span.hpp"

int main(void)
{
	/*------------- Initialization -------------*/

			std::cout << std::endl;

	std::vector<int>	vec = {5, 37, 13, 97, 83};
	Span 				sp(5);
	Span 				sp_range;
//	Span				sp_rand(10000);

			std::cout << std::endl;

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

			std::cout << std::endl;

	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

			std::cout << std::endl;

	sp_range.addRangeNum(vec.begin(), vec.end());

			std::cout << std::endl;

//	sp_rand.addRandom(10000);

//			std::cout << std::endl;

	std::cout << "Normal Span" << std::endl;
	sp.printSpan();
	std::cout << "Range Span" << std::endl;
	sp_range.printSpan();
//	std::cout << "Random Span" << std::endl;
//	sp_rand.printSpan();
//	std::cout << "\nLength Random Span : " << sp_rand.getLenCont() << std::endl;

			std::cout << std::endl;

	/*--------------- Test copies ---------------*/
/*
			std::cout << std::endl;

	Span	sp2(sp);
	Span	sp3;

			std::cout << std::endl;

	sp3 = sp;

			std::cout << std::endl;

	sp.printSpan();
	sp2.printSpan();
	sp3.printSpan();

			std::cout << std::endl;
*/
	/*--------------- Test spans ---------------*/

			std::cout << std::endl;

	std::cout << sp.shortestSpan() << std::endl; // 2
	std::cout << sp.longestSpan() << std::endl; // 14

			std::cout << std::endl;

	return 0;
}
