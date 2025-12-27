#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
	{
		this->stock[i] = NULL;
	}
	std::cout << "MateriaSource constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < 4; ++i)
	{
		this->stock[i] = NULL;
		if (copy.stock[i] != NULL)
			this->stock[i] = copy.stock[i]->clone();
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->stock[i] != NULL)
			delete this->stock[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int i;

	i = 0;
	while (i < 4 && this->stock[i] != NULL)
	{
		++i;
	}
	if (i == 4)
	{
		std::cerr << "MateriaSource's stock is full, no action taken" << std::endl;
	}
	else
	{
		this->stock[i] = m->clone();
	}
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int i;

	i = 0;
	while(i < 4 && (this->stock[i] == NULL || this->stock[i]->getType() != type))
	{
		++i;
	}
	if (i == 4)
	{
		std::cerr << "MateriaSource didn't find the Materia asked" << std::endl;
		return (0);
	}
	return (this->stock[i]->clone());
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->stock[i] != NULL)
		{
			delete this->stock[i];
			this->stock[i] = NULL;
		}
		if (other.stock[i] != NULL)
			this->stock[i] = other.stock[i]->clone();
	}
	std::cout << "MateriaSource copy assignement operator called" << std::endl;
	return (*this);
}
