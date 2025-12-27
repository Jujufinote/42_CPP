#include "Ground.hpp"

AMateria**	Ground::items = NULL;
int			Ground::length = 0;

Ground::Ground()
{
	std::cout << "Ground constructor called" << std::endl;
	return ;
}

Ground::Ground(Ground const &copy)
{
	std::cout << "Ground copy constructor called" << std::endl;
	return;
}

Ground::~Ground()
{
	std::cout << "Ground destructor called" << std::endl;
	return ;
}

void	Ground::addItem(AMateria *item)
{
	if (Ground::items == NULL)
	{
		Ground::items = new AMateria *[1];
	}
	else
	{
		AMateria**	temp = new AMateria *[length + 1];
		for (int i = 0; i < Ground::length; ++i)
		{
			temp[i] = Ground::items[i];
		}
		delete[] Ground::items;
		Ground::items = temp;
	}
	Ground::items[Ground::length] = item;
	Ground::length++;
	std::cout << item->getType() << " threw on the Ground" << std::endl;
	return ;
}

AMateria	*Ground::suppItem(std::string type)
{
	int			is_supp = 0;
	int			is_item;
	AMateria	*item = NULL;

	is_item = 0;
	for (int i = 0; i < Ground::length && is_item == 0; i++)
	{
		if (Ground::items[i]->getType() == type)
			is_item++;
	}
	if (is_item == 0)
	{
		std::cerr << "No " << type << "found on Ground" << std::endl;
		return (0);
	}
	if (Ground::length == 1)
	{
		Ground::length = 0;
		AMateria* temp = Ground::items[0];
		delete[] Ground::items;
		Ground::items = NULL;
		std::cout << temp->getType() << " picked up from Ground" << std::endl;
		return (temp);
	}
	AMateria**	temp = new AMateria *[length - 1];
	for (int i = 0; i < Ground::length; ++i)
	{
		if (is_supp == 0 && Ground::items[i]->getType() == type)
		{
			item = Ground::items[i];
			is_supp = 1;
		}
		else if (is_supp == 1)
			temp[i - 1] = Ground::items[i];
		else
			temp[i] = Ground::items[i];
	}
	delete[] Ground::items;
	Ground::items = temp;
	Ground::length--;
	std::cout << item->getType() << " picked up from Ground" << std::endl;
	return (item);
}

void	Ground::destructor(void)
{
	for (int i = 0; i < length; i++)
	{
		delete Ground::items[i];
	}
	delete[] Ground::items;
	Ground::items = NULL;
	Ground::length = 0;
	std::cout << "Ground cleaned" << std::endl;
	return ;
}

Ground	&Ground::operator=(Ground const &other)
{
	std::cout << "Ground copy assignement operator called" << std::endl;
	return (*this);
}
