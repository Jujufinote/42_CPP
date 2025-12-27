#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << "MutantStack default constructor called" << std::endl;
	return ;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const& copy)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
	this = copy;
	return ;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

/*---------------------------------------------------------------------------------------------------------------*/

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const& other)
{
	std::cout << "MutantStack assignement operator called" << std::endl;
	this = other;
	return (*this);
}
