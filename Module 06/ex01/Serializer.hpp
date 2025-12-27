#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const& copy);

	public:
		virtual	~Serializer(void);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserializer(uintptr_t raw);

		Serializer&	operator=(Serializer const& other);
};

#endif
