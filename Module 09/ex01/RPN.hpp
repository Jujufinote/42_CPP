#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cctype>

class RPN
{
	private :
		std::stack<int>	_buffer;

	public :
		RPN(void); // canonical
		RPN(RPN const& copy); // canonical
		virtual ~RPN(void); // canonical

		int		getNumber(void); // return top num and pop it
		int		getSize(void) const;
		
		void	addNumber(int number);
		void	merge(int symbol);

		RPN		&operator=(RPN const& other); // canonical
};

//std::ostream&	operator<<(std::ostream& o, RPN const& other);

#endif
