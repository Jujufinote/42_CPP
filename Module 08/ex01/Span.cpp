#include "Span.hpp"

Span::Span(void) : max_len(100)
{
	std::cout << "Span default constructor called : max num stocked : 100" << std::endl;
	return ;
}

Span::Span(unsigned int N) : max_len(N)
{
	std::cout << "Span constructor called" << std::endl;
	return ;
}

Span::Span(Span const& copy) : max_len(copy.max_len)
{
	this->cont = copy.cont;
	std::cout << "Span copy constructor called" << std::endl;
	return ;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

int	Span::getLenCont(void) const
{
	return (this->cont.size());
}

/*---------------------------------------------------------------------------------------------------------------*/

void	Span::addNumber(int num)
{
   if (this->cont.size() == this->max_len)
	   throw std::runtime_error("No more space left in Span");
   this->cont.push_back(num);
   std::cout << num << " added to Span" << std::endl; 
   return ;
}

void	Span::addRangeNum(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	std::vector<int>::const_iterator	now = begin;
	int									size = 0;

	for (now; now != end; now++)
	{
		size++;
	}
	if (this->cont.size() + size > this->max_len)
		throw std::runtime_error("Cannot add : too many numbers, length will overflow");
	this->cont.insert(this->cont.end(), begin, end);
	std::cout << "Numbers in range " << *begin <<  " to " << *(end - 1) << " added" << std::endl;
	return ;
}

void	Span::addRandom(unsigned int size)
{
	if (this->cont.size() + size > this->max_len)
		throw std::runtime_error("Cannot add : too many numbers, length will overflow");
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		this->addNumber(rand());
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

int	Span::shortestSpan(void) const
{
	switch (this->cont.size())
	{
		case 0:
		{
			throw std::runtime_error("No number stocked, cannot calculate the shortest span");
			break;
		}

		case 1:
		{
			throw std::runtime_error("Only one number stocked, cannot calculate the shortest span");
			break;
		}

		default:
			break;
	}

	std::vector<int>					sorted = this->cont;
	
	std::sort(sorted.begin(), sorted.end());
	
	std::vector<int>::const_iterator	now = sorted.begin();
	std::vector<int>::const_iterator	next = now + 1;
	int									result = *next - *now;

	while (next != sorted.end())
	{
		if (result > *next - *now)
			result = *next - *now;
		++now;
		++next;
	}
	return (result);
}

int	Span::longestSpan(void) const
{
	switch (this->cont.size())
	{
		case 0:
		{
			throw std::runtime_error("No number stocked, cannot calculate the longest span");
			break;
		}

		case 1:
		{
			throw std::runtime_error("Only one number stocked, cannot calculate the longest span");
			break;
		}
		
		default:
			break;
	}

	std::vector<int>					sorted = this->cont;

	std::sort(sorted.begin(), sorted.end());

	std::vector<int>::const_iterator	little = sorted.begin();
	std::vector<int>::const_iterator	big = sorted.end() - 1;

	return (*big - *little);
}

void	Span::printSpan(void) const
{
	std::vector<int>::const_iterator	i = this->cont.begin();

	if (this->cont.size() == 0)
	{
		std::cout << "Span : <\033[3mempty\033[0m>" << std::endl;
		return ;
	}
	std::cout << "Span : {";
	for (i; i != this->cont.end() - 1; ++i)
	{
		std::cout << *i << ", ";
	}
	std::cout << *i;
	std::cout << "}" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

Span&	Span::operator=(Span const& other)
{
	if (this->max_len < other.cont.size())
		throw std::runtime_error("Cannot assign : length not compatible");
	this->cont = other.cont;
	std::cout << "Span copy assignement operator called" << std::endl;
	return (*this);
}
