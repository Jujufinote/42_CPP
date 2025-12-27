#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
//	std::cout << "PmergeMe default constructor called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(std::vector<unsigned int> const& v, std::list<unsigned int> const& l)
{

	struct timeval	start, end;

	this->_jacobsthal.push_back(0);
	this->_jacobsthal.push_back(1);
	this->_vbuffer = v;
	this->_vsortedbuffer = v;
	this->_lbuffer = l;
	this->_lsortedbuffer = l;

//	std::cout << "PmergeMe constructor called" << std::endl;

	gettimeofday(&start, NULL);
	_Vsort();
	gettimeofday(&end, NULL);
	this->_vtime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	_Lsort();
	gettimeofday(&end, NULL);
	this->_ltime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	return ;
}

PmergeMe::PmergeMe(PmergeMe const& copy)
{
	this->_vbuffer = copy._vbuffer;
	this->_vsortedbuffer = copy._vsortedbuffer;
	this->_vtime = copy._vtime;

	this->_lbuffer = copy._lbuffer;
	this->_lsortedbuffer = copy._lsortedbuffer;
	this->_ltime = copy._ltime;

//	std::cout << "PmergeMe copy constructor called" << std::endl;
	return ;
}

PmergeMe::~PmergeMe(void)
{
//	std::cout << "PmergeMe destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

//array of jacobsthal numbers created by the recursive formula J(n-1) + 2J(n-2)
void	PmergeMe::_Jacobsthalrecursive(int const& pend_size)
{
	// indexes (we use then because when pop or push there is a new allocation so iterator changes but not indexes)
	int	before2 = 0;
	int	before = 1;

	while (pend_size >= this->_jacobsthal[before])
	{
		this->_jacobsthal.push_back(this->_jacobsthal[before] + 2 * this->_jacobsthal[before2]);
		before2++;
		before++;
	}
	this->_jacobsthal.pop_back(); // because we dont need when before > pend_size

	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

PmergeMe&	PmergeMe::operator=(PmergeMe const& other)
{
	this->_vbuffer = other._vbuffer;
	this->_vsortedbuffer = other._vsortedbuffer;
	this->_vtime = other._vtime;

	this->_lbuffer = other._lbuffer;
	this->_lsortedbuffer = other._lsortedbuffer;
	this->_ltime = other._ltime;

//	std::cout << "PmergeMe copy assignement operator called" << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, PmergeMe const& other)
{
	o << std::endl;

	// vector
	other.displayVBuffer();
	other.displayVSortedBuffer();
/*
	// list
	other.displayLBuffer();
	other.displayLSortedBuffer();
*/
	// time
	other.displayVTime();
	other.displayLTime();

	return o;
}
