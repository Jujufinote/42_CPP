#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private :
		T*				array;
		unsigned int	len;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array<T> const& copy);
		virtual ~Array(void);

		void			printArray(void) const;

		unsigned int	size(void) const;

		Array<T>&		operator=(Array<T> const& other);
		T&				operator[](int i);
};

# include "Array.tpp"

#endif
