#include "Serializer.hpp"

int	main(void)
{
	Data	data;
	Data*	ptr = &data;
	Data*	result;

	
	data.var = 42;

	result = Serializer::deserializer(Serializer::serialize(ptr));

	std::cout << ptr << " " << ptr->var << std::endl;
	std::cout << result << " " << result->var << std::endl;

	return 0;
}
