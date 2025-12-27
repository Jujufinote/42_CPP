#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sys/time.h>
# include <algorithm>
# include <cctype>
# include <vector>
# include <list>

class PmergeMe
{
	private :
		PmergeMe(void);									// canonical
		PmergeMe(PmergeMe const& copy); 				// canonical
		PmergeMe	&operator=(PmergeMe const& other);	// canonical

		std::vector<unsigned int>	_jacobsthal;
		void						_Jacobsthalrecursive(int const& pend_size);

		std::vector<unsigned int>	_vbuffer;
		std::vector<unsigned int>	_vsortedbuffer;
		double						_vtime;
		void						_Vsort(void);
		void						_Vswapl(int const& length);
		void						_Vseparation(int const& length, std::vector<unsigned int>& main, std::vector<unsigned int>& pend);
		void						_Vinsertion(int const& length, std::vector<unsigned int>& main, std::vector<unsigned int>& pend);

		std::list<unsigned int>		_lbuffer;
		std::list<unsigned int>		_lsortedbuffer;
		double						_ltime;
		void						_Lsort(void);
		void						_Lswapl(int const& length);
		void						_Lseparation(int const& length, std::list<unsigned int>& main, std::list<unsigned int>& pend);
		void						_Linsertion(int const& length, std::list<unsigned int>& main, std::list<unsigned int>& pend);
	
	public :
		PmergeMe(std::vector<unsigned int> const& v, std::list<unsigned int> const& l);
		virtual ~PmergeMe(void); // canonical

		void	displayVBuffer(void) const;
		void	displayVSortedBuffer(void) const;
		void	displayLBuffer(void) const;
		void	displayLSortedBuffer(void) const;
		void	displayVTime(void) const;
		void	displayLTime(void) const;

};

std::list<unsigned int>::iterator		operator+(std::list<unsigned int>::iterator const& container, int const& num);
std::list<unsigned int>::iterator		operator-(std::list<unsigned int>::iterator const& container, int const& num);
void									operator+=(std::list<unsigned int>::iterator& container, int const& num);
std::list<unsigned int>::const_iterator	operator+(std::list<unsigned int>::const_iterator const& container, int const& num);
std::list<unsigned int>::const_iterator	operator-(std::list<unsigned int>::const_iterator const& container, int const& num);
void									operator+=(std::list<unsigned int>::const_iterator& container, int const& num);

std::ostream&	operator<<(std::ostream& o, PmergeMe const& other);

#endif
