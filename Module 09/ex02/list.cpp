#include "PmergeMe.hpp"

// swap on groups of length elements
void	PmergeMe::_Lswapl(int const& length)
{
	std::list<unsigned int>::iterator	element1 = _lsortedbuffer.begin() + length - 1;
	std::list<unsigned int>::iterator	element2 = element1 + length;
	int									total_length = 2 * length;

	while (total_length <= _lsortedbuffer.size())
	{
		if (*element1 > *element2)
		{
			for (int size = length - 1; size >= 0; --size)
			{
				std::swap(*(element1 - size), *(element2 - size));
			}
		}
		element1 += 2 * length;
		element2 += 2 * length;
		total_length += 2 * length; 
	}

	return ;
}

// binary search in range [b1, ax) for groups of length elements, remember that b1 can be > than other bs so it needs to be include in the search
std::list<unsigned int>::const_iterator	b_search(int const& length, std::list<unsigned int> const& main, std::list<unsigned int>::const_iterator ax, unsigned int const& val)
{
	std::list<unsigned int>::const_iterator	bx = main.begin();
	int											nb_pos = 0;

	if (ax == main.end())
	{
		nb_pos = main.size() / length + main.size() % 2;
	}
	else
	{
		// because bx is on the left element of a group and ax on the right, we need to + length - 1 to place bx on the left element of its group
		for (bx; bx + length - 1 != ax ; bx += length)
		{
			++nb_pos;
		}
	}

	nb_pos = nb_pos / 2 + nb_pos % 2;
	bx = main.begin();
	for (nb_pos; nb_pos >= 1; nb_pos = nb_pos / 2 + nb_pos % 2)
	{
		if (bx == main.end())
			break;
		if ((bx + nb_pos * length == main.end() && val > *(main.end() - 1)) || val > *(bx + length - 1 + nb_pos * length))
			bx += nb_pos * length;
		if (nb_pos == 1)
			break;
	}
	if (bx != main.end() && val > *(bx + length - 1)) // if end, no need to add
		bx += length;
	return (bx);
	return (bx);
}

/*---------------------------------------------------------------------------------------------------------------*/

// main fonction
void	PmergeMe::_Lsort(void)
{
	int	length = 1;

	// merge sort
	while (length <= _lsortedbuffer.size() / 2)
	{
		_Lswapl(length);
		length *= 2;
	}

	// length reajustment at the while exit
	length /= 2;


/*	std::cout << "\n merge:   ";
	for (std::list<unsigned int>::const_iterator i = this->_lsortedbuffer.begin(); i != this->_lsortedbuffer.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
*/

	// Jacobsthal insertion sort
	std::list<unsigned int>	main;
	std::list<unsigned int>	pend;
	while (length >= 1)
	{
		// we clear previouses separation
		main.clear();
		pend.clear();
/*
		std::cout << "\n length : " << length << std::endl;
		std::cout << "\n separation\n";
*/
		_Lseparation(length, main, pend);
		_Linsertion(length, main, pend);
/*
		std::cout << "\n after insertion\n";
		std::cout << "buffer:   ";
		for (std::list<unsigned int>::const_iterator i = this->_lsortedbuffer.begin(); i != this->_lsortedbuffer.end(); ++i)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
*/
		length /= 2;
	}

	return ;
}

// split in to 2 arrays : main and pend
void	PmergeMe::_Lseparation(int const& length, std::list<unsigned int>& main, std::list<unsigned int>& pend)
{

	/*
		pend (b elements like group of elements in [left, rigth), right not included)
		left : first element of now group
		right : first element of next group
	*/

	// indexes
	int	left = 2 * length; // to initialize we skip b1 to add it directly in main later, therefore next b is at length 3, "length of index 2"
	int	right = left + length;

	int	total_length = 3 * length; // we already passed 3 length in buffer
	while (total_length <= this->_lsortedbuffer.size())
	{
		pend.insert(pend.end(), this->_lsortedbuffer.begin() + left, this->_lsortedbuffer.begin() + right);
		this->_lsortedbuffer.erase(this->_lsortedbuffer.begin() + left, this->_lsortedbuffer.begin() + right);

		// we add only 1 length because we just erased one
		left += length;
		right += length;
		total_length += length;
	}

/*
	std::cout << "pend:   ";
	for (std::list<unsigned int>::const_iterator i = pend.begin(); i != pend.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
*/

	// main (a elements like group of elements in [left, rigth), right not included)
	left = 0;
	right = length;
	total_length = length;

	while (total_length <= _lsortedbuffer.size())
	{
		main.insert(main.end(), this->_lsortedbuffer.begin() + left, this->_lsortedbuffer.begin() + right);
		_lsortedbuffer.erase(this->_lsortedbuffer.begin() + left, this->_lsortedbuffer.begin() + right);

		//we dont add any length at our indexes because we just erased one
	}

	// if there anything more left, it will not be used in insertion and still stored in buffer

/*
	std::cout << "main:   ";
	for (std::list<unsigned int>::const_iterator i = main.begin(); i != main.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	std::cout << "buffer:   ";
	for (std::list<unsigned int>::const_iterator i = this->_lsortedbuffer.begin(); i != this->_lsortedbuffer.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
*/
	return ;
}

// insertion with jacobsthal
void	PmergeMe::_Linsertion(int const& length, std::list<unsigned int>& main, std::list<unsigned int>& pend)
{
	// clear previous sequence
	this->_jacobsthal.clear();
	this->_jacobsthal.push_back(0);
	this->_jacobsthal.push_back(1);

	// set jacobsthal sequence
	_Jacobsthalrecursive(pend.size() / length);// / length because we need thed number of elements b and not literally the size of the array
	
	// indexes
	std::vector<unsigned int>::const_iterator	j = _jacobsthal.begin() + 3;	// initialized at +3 because we ignore the "parents" and first jacobsthal already done
	int											left = -length;					// left number of group in pend like [left, rigth)
	int											right = left + length;			// last + 1 number of group in pend like [left, rigth)
	int											idx = -1;						// index of right "jacobsthal" element a, last + 1 member of a group like [left, right), beginning at -1 because equivalent to 0 for normal indexing
	int											num = 1;						// number of elements already inserted (b1 already inserted)
	int											diff_j = 0;						// number of elements of pend we need to insert

	if (_jacobsthal.size() > 3)
	{
//		std::cout << "\n insert in jacobsthal order..." << std::endl;
		for (j; j != _jacobsthal.end(); ++j)
		{
			diff_j = *j - *(j - 1);
			left += diff_j * length;
			right += diff_j * length;
			idx = -1 + (*j + num) * length;
			for (diff_j; diff_j > 0; --diff_j)
			{
/*
				std::cout << "main:   ";
				for (std::list<unsigned int>::const_iterator i = main.begin(); i != main.end(); ++i)
				{
					std::cout << *i << " ";
				}
				std::cout << std::endl;
			
				std::cout << "pend:   ";
				for (std::list<unsigned int>::const_iterator i = pend.begin(); i != pend.end(); ++i)
				{
					std::cout << *i << " ";
				}
				std::cout << std::endl;
*/
				// we always insert in range [b1, ax) for a pend element bx
				main.insert(b_search(length, main, main.begin() + idx, *(pend.begin() + right - 1)), pend.begin() + left, pend.begin() + right);
				pend.erase(pend.begin() + left, pend.begin() + right);
				++num;
				left -= length;
				right -= length;
			}
		}
	}

//	std::cout << "\n insert last pend..." << std::endl;

	// we insert the rest of pend in reverse order in main
	left = pend.size() - length;
	while (pend.size() > 0)
	{
/*		
		std::cout << "main:   ";
		for (std::list<unsigned int>::const_iterator i = main.begin(); i != main.end(); ++i)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	
		std::cout << "pend:   ";
		for (std::list<unsigned int>::const_iterator i = pend.begin(); i != pend.end(); ++i)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
*/
		// we always insert in range [b1, ax) for a pend element bx
		main.insert(b_search(length, main, main.end(), *(pend.end() - 1)), pend.begin() + left, pend.end());
		pend.erase(pend.begin() + left, pend.end());
		left -= length;
	}

	// we insert main in buffer iterate insertion on another group length until length == 1
	this->_lsortedbuffer.insert(this->_lsortedbuffer.begin(), main.begin(), main.end());
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

void	PmergeMe::displayLBuffer(void) const
{
	std::cout << "Before:   ";
	for (std::list<unsigned int>::const_iterator i = this->_lbuffer.begin(); i != this->_lbuffer.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return ;
}

void	PmergeMe::displayLSortedBuffer(void) const
{
	std::cout << "After:    ";
	for (std::list<unsigned int>::const_iterator i = this->_lsortedbuffer.begin(); i != this->_lsortedbuffer.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return ;
}

void	PmergeMe::displayLTime(void) const
{
	std::cout << "Time to process a range of " << this->_lsortedbuffer.size() << " elements with std::list : " << this->_ltime << " us" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

std::list<unsigned int>::iterator	operator+(std::list<unsigned int>::iterator const& container, int const& num)
{
	std::list<unsigned int>::iterator	result = container;

	for (int i = 0; i < num; i++)
	{
		result++;
	}
	return (result);
}

std::list<unsigned int>::iterator		operator-(std::list<unsigned int>::iterator const& container, int const& num)
{
	std::list<unsigned int>::iterator	result = container;

	for (int i = 0; i < num; i++)
	{
		result--;
	}
	return (result);
}

void	operator+=(std::list<unsigned int>::iterator& container, int const& num)
{
	for (int i = 0; i < num; i++)
	{
		container++;
	}
	return ;
}

std::list<unsigned int>::const_iterator	operator+(std::list<unsigned int>::const_iterator const& container, int const& num)
{
	std::list<unsigned int>::const_iterator	result = container;

	for (int i = 0; i < num; i++)
	{
		result++;
	}
	return (result);
}

std::list<unsigned int>::const_iterator	operator-(std::list<unsigned int>::const_iterator const& container, int const& num)
{
	std::list<unsigned int>::const_iterator	result = container;

	for (int i = 0; i < num; i++)
	{
		result--;
	}
	return (result);
}

void	operator+=(std::list<unsigned int>::const_iterator& container, int const& num)
{
	for (int i = 0; i < num; i++)
	{
		container++;
	}
	return ;
}
