#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack(void);
		MutantStack(MutantStack const& copy);
		virtual ~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator		begin(void);
		iterator		end(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;

		MutantStack&	operator=(MutantStack const& other);
};

# include "MutantStack.tpp"

#endif
