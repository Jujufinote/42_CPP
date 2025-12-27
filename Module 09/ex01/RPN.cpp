#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "RPN default constructor called" << std::endl;
	return ;
}

RPN::RPN(RPN const& copy)
{
	std::cout << "RPN copy constructor called" << std::endl;
	this->_buffer = copy._buffer;
	return ;
}

RPN::~RPN(void)
{
	std::cout << "RPN destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

int	RPN::getNumber(void)
{
	int	num = this->_buffer.top();
	this->_buffer.pop();
	return (num);
}

int	RPN::getSize(void) const
{
	return (this->_buffer.size());
}

/*---------------------------------------------------------------------------------------------------------------*/

void	RPN::addNumber(int number)
{
	this->_buffer.push(number);
	return ;
}

/*
	We need to test if there are at least two numbers to "merge" before merging
*/
void	RPN::merge(int symbol)
{
	// test if there is a number before copy and delete
	if (this->_buffer.empty() == true)
	{
		throw std::runtime_error("Error : missing number");
	}
	int	num2 = this->_buffer.top();
	this->_buffer.pop();

	// test if there is another number before copy and delete
	if (this->_buffer.empty() == true)
	{
		throw std::runtime_error("Error : missing number");
	}
	int num1 = this->_buffer.top();
	this->_buffer.pop();


	switch (symbol)
	{
		case '*' :
		{
			this->_buffer.push(num1 * num2);
			break;
		}

		case '+' :
		{
			this->_buffer.push(num1 + num2);
			break ;
		}

		case '-' :
		{
			this->_buffer.push(num1 - num2);
			break ;
		}

		case '/' :
		{
			this->_buffer.push(num1 / num2);
			break ;
		}
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

RPN&	RPN::operator=(RPN const& other)
{
	std::cout << "RPN copy assignement operator called" << std::endl;
	this->_buffer = other._buffer;
	return (*this);
}
