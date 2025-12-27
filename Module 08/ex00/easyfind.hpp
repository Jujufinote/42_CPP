#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

//standard container
# include <vector>
# include <deque>
# include <list>

/*

/associative containers
# include <map>
# include <set>

/container adaptators (container is an adjective of adaptator)
# include <stack>
# include <queue>
# include <priority_queue>

*/

template<typename T>
typename T::iterator	easyfind(T cont, int element)
{
	typename T::iterator	i = cont.begin();

	for (i; i != cont.end(); ++i)
	{
		if (*i == element)
			return i;
	}
	throw std::runtime_error("No element found");
}

#endif
