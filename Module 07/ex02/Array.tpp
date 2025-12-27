#include "Array.hpp"

template<typename T>
Array<T>::Array(void)
{
	std::cout << "Array default constructor called" << std::endl;
	this->array = nullptr;
	this->len = 0;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array constructor called" << std::endl;
	if (n == 0)
	{
		this->array = nullptr;
		this->len = 0;
		return ;
	}
	this->array = new T[n];
	for (int i = 0; i < n; ++i)
	{
		this->array[i] = 0;
	}
	this->len = n;
	return ;
}

template<typename T>
Array<T>::Array(Array<T> const& copy)
{
	std::cout << "Array copy constructor called" << std::endl;
	if (copy.len == 0)
	{
		this->array = nullptr;
		this->len = 0;
		return ;
	}
	this->array = new T[copy.len];
	for (int i = 0; i < copy.len; ++i)
	{
		this->array[i] = copy.array[i];
	}
	this->len = copy.len;
	return ;
}

template<typename T>
Array<T>::~Array(void)
{
	if (this->len != 0)
		delete[] this->array;
	std::cout << "Array destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

template<typename T>
void	Array<T>::printArray(void) const
{
	if (this->len == 0)
	{
		std::cout << "Empty array" << std::endl;
	}
	for (int i = 0; i < this->len; ++i)
	{
		std::cout << i << " : " << this->array[i] << std::endl;
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->len);
}

/*---------------------------------------------------------------------------------------------------------------*/

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const& other)
{
	std::cout << "Array copy assignement operator called" << std::endl;
	if (this->len != 0)
		delete[] this->array;
	if (other.len == 0)
	{
		this->array = nullptr;
		this->len = 0;
		return (*this);
	}
	this->array = new T[other.len];
	for (int i = 0; i < other.len; ++i)
	{
		this->array[i] = other.array[i];
	}
	this->len = other.len;
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](int i)
{
	if (i > this->len - 1 || i < 0)
		throw std::runtime_error("Index out of bounds");
	return (this->array[i]);
}
