#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cctype>

template<typename T, typename Func>
void	iter(T* adr, std::size_t len, Func f)
{
	for (std::size_t i = 0; i < len; ++i)
	{
		f(adr[i]);
	}
	return ;
}

template<typename T, typename Func>
void	iter(const T* adr, std::size_t len, Func f)
{
	for (std::size_t i = 0; i < len; ++i)
	{
		f(adr[i]);
	}
	return ;
}

#endif
