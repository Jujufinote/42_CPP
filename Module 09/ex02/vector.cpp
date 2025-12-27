#include "PmergeMe.hpp"

// swap on groups of length elements
void	PmergeMe::_Vswapl(int const& length)
{
	std::vector<unsigned int>::iterator	element1 = _vsortedbuffer.begin() + length - 1;
	std::vector<unsigned int>::iterator	element2 = element1 + length;
	int									total_length = 2 * length;

	while (total_length <= _vsortedbuffer.size())
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
std::vector<unsigned int>::const_iterator	b_search(int const& length, std::vector<unsigned int> const& main, std::vector<unsigned int>::const_iterator ax, unsigned int const& val)
{
	std::vector<unsigned int>::const_iterator	bx = main.begin();
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
}

/*---------------------------------------------------------------------------------------------------------------*/

// main fonction
void	PmergeMe::_Vsort(void)
{
	int	length = 1;

	// merge sort
	while (length <= _vsortedbuffer.size() / 2)
	{
		_Vswapl(length);
		length *= 2;
	}

	// length reajustment at the while exit
	length /= 2;

	// Jacobsthal insertion sort
	std::vector<unsigned int>	main;
	std::vector<unsigned int>	pend;
	while (length >= 1)
	{
		// we clear previouses separation
		main.clear();
		pend.clear();
	
		_Vseparation(length, main, pend);
		_Vinsertion(length, main, pend);

		length /= 2;
	}

	return ;
}

// split in to 2 arrays : main and pend
void	PmergeMe::_Vseparation(int const& length, std::vector<unsigned int>& main, std::vector<unsigned int>& pend)
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
	while (total_length <= this->_vsortedbuffer.size())
	{
		pend.insert(pend.end(), this->_vsortedbuffer.begin() + left, this->_vsortedbuffer.begin() + right);
		this->_vsortedbuffer.erase(this->_vsortedbuffer.begin() + left, this->_vsortedbuffer.begin() + right);

		// we add only 1 length because we just erased one
		left += length;
		right += length;
		total_length += length;
	}

	// main (a elements like group of elements in [left, rigth), right not included)
	left = 0;
	right = length;
	total_length = length;

	while (total_length <= _vsortedbuffer.size())
	{
		main.insert(main.end(), this->_vsortedbuffer.begin() + left, this->_vsortedbuffer.begin() + right);
		_vsortedbuffer.erase(this->_vsortedbuffer.begin() + left, this->_vsortedbuffer.begin() + right);

		//we dont add any length at our indexes because we just erased one
	}

	// if there anything more left, it will not be used in insertion and still stored in buffer
	return ;
}

// insertion with jacobsthal
void	PmergeMe::_Vinsertion(int const& length, std::vector<unsigned int>& main, std::vector<unsigned int>& pend)
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
	int											idx = -1;						// index of right "jacobsthal" element a, last + 1 member of a group like [left, right)
	int											num = 1;						// number of elements already inserted (b1 already inserted)
	int											diff_j = 0;						// number of elements of pend we need to insert

	// insert in jacobsthal order
	if (_jacobsthal.size() > 3)
	{
		for (j; j != _jacobsthal.end(); ++j)
		{
			diff_j = *j - *(j - 1);
			left += diff_j * length;
			right += diff_j * length;
			idx = -1 + (*j + num) * length;
			for (diff_j; diff_j > 0; --diff_j)
			{
				// we always insert in range [b1, ax) for a pend element bx
				main.insert(b_search(length, main, main.begin() + idx, *(pend.begin() + right - 1)), pend.begin() + left, pend.begin() + right);
				pend.erase(pend.begin() + left, pend.begin() + right);
				++num;
				left -= length;
				right -= length;
			}
		}
	}

	// we insert the rest of pend in reverse order in main
	left = pend.size() - length;
	while (pend.size() > 0)
	{
		// we always insert in range [b1, ax) for a pend element bx
		main.insert(b_search(length, main, main.end(), *(pend.end() - 1)), pend.begin() + left, pend.end());
		pend.erase(pend.begin() + left, pend.end());
		left -= length;
	}

	// we insert main in buffer iterate insertion on another group length until length == 1
	this->_vsortedbuffer.insert(this->_vsortedbuffer.begin(), main.begin(), main.end());
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

void	PmergeMe::displayVBuffer(void) const
{
	std::cout << "Before:   ";
	for (std::vector<unsigned int>::const_iterator i = this->_vbuffer.begin(); i != this->_vbuffer.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return ;
}

void	PmergeMe::displayVSortedBuffer(void) const
{
	std::cout << "After:    ";
	for (std::vector<unsigned int>::const_iterator i = this->_vsortedbuffer.begin(); i != this->_vsortedbuffer.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return ;
}

void	PmergeMe::displayVTime(void) const
{
	std::cout << "Time to process a range of " << this->_vsortedbuffer.size() << " elements with std::vector : " << this->_vtime << " us" << std::endl;
	return ;
}
