#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
	/*---------- Initialization ----------*/

			std::cout << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

			std::cout << std::endl;

	/*----------- Test equality -----------*/

			std::cout << std::endl;

	std::cout << "Test equality of values..." << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value on index : " << i << " !!" << std::endl;
		}
	}
	std::cout << "End of test" << std::endl;

			std::cout << std::endl;

	/*--------- Test out of bound ---------*/

			std::cout << std::endl;

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
			std::cout << std::endl;

	/*------------ Test copies ------------*/

			std::cout << std::endl;

	Array<int> tmp;
	tmp = numbers;
	Array<int> test(tmp);

			std::cout << std::endl;

	std::cout << "Test equality of values..." << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (tmp[i] != numbers[i])
		{
			std::cerr << "Between tmp and numbers :";
			std::cerr << "didn't save the same value on index : " << i << " !!" << std::endl;
		}
		if (test[i] != numbers[i])
		{
			std::cerr << "Between test and numbers :";
			std::cerr << "didn't save the same value on index : " << i << " !!" << std::endl;
		}
		if (tmp[i] != test[i])
		{
			std::cerr << "Between tmp and test :";
			std::cerr << "didn't save the same value on index : " << i << " !!" << std::endl;
		}
	}
	std::cout << "End of test" << std::endl;

			std::cout << std::endl;

	/*--------- Test modify value ---------*/

			std::cout << std::endl;

	std::cout << "Array of numbers :" << std::endl;
	numbers.printArray();
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "\nArray of numbers v2 :" << std::endl;
	numbers.printArray();

			std::cout << std::endl;


	//destructor
	delete[] mirror;
	return 0;
}
