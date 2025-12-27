#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <ctime>
# include <cstdlib>

class Span
{
	private :
		Span(Span const& copy);
		Span&	operator=(Span const& other);

		std::vector<int>	cont;
		unsigned int const	max_len;
	
		
	public:
		Span(void);
		Span(unsigned int N);
		virtual ~Span(void);
	
		int		getLenCont(void) const;

		void	addNumber(int num);
		void	addRangeNum(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		void	addRandom(unsigned int size);

		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	printSpan(void) const;

};

#endif
