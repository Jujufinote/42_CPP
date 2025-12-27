#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserializer(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
	return ;
}

Serializer::Serializer(Serializer const& copy)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	return ;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

Serializer&	Serializer::operator=(Serializer const& other)
{
	std::cout << "Serializer copy assignement operator called" << std::endl;
	return (*this);
}
