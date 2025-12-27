#include "Character.hpp"

Character::Character()
{
	this->name = "Anonym";
	for (int i = 0; i < 4; ++i)
	{
		this->inventory[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
	return ;
}

Character::Character(std::string const name)
{
	this->name = name;
	for (int i = 0; i < 4; ++i)
	{
		this->inventory[i] = NULL;
	}
	std::cout << "Character " << this->name << " constructor called" << std::endl;
	return ;
}

Character::Character(Character const &copy)
{
	this->name = copy.name;
	for (int i = 0; i < 4; ++i)
	{
		this->inventory[i] = NULL;
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i]->clone();
	}
	std::cout << "Character " << this->name << " copy constructor called" << std::endl;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	std::cout << "Character " << this->name << " destructor called" << std::endl;
	return ;
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

void	Character::showInventory(void) const
{
	std::cout << "\t\tInventory of " << this->name << std::endl << std::endl;
	std::cout << "\t" << std::setw(10) << "INDEX" << " |" << "TYPE" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t" << std::setw(10) << i << " |";
		if (this->inventory[i] != NULL)
			std::cout << this->inventory[i]->getType() << std::endl;
		else
			std::cout << "NULL" << std::endl;
	}
	std::cout << std::endl;
	return ;
}

void	Character::equip(AMateria *m)
{
	int i;

	if (m == 0)
	{
		std::cerr << "No materia can be equiped (no action taken)" << std::endl;
		return ;
	}
	i = 0;
	while (i < 4 && this->inventory[i] != NULL)
	{
		++i;
	}
	if (i == 4)
	{
		std::cerr << this->name << " has full inventory" << std::endl;
		Ground::addItem(m);
	}
	else
	{
		this->inventory[i] = m;
		std::cout << this->name << " equiped " << m->getType() << std::endl;
	}
	return ;
}

void	Character::unequip(int idx)
{
	if (idx > 3)
	{
		std::cerr << "Could not access to this space, out of inventory" << std::endl;
		return ;
	}
	if (this->inventory[idx] != NULL)
	{
		std::cout << this->name << " unequiped " << this->inventory[idx]->getType() << std::endl;
		Ground::addItem(this->inventory[idx]);
		this->inventory[idx] = NULL;
	}
	else
	{
		std::cerr << this->name << " tries to unequip empty inventory space (no action taken)" << std::endl;
	}
	return ;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx > 3)
	{
		std::cerr << "Could not access to this space, out of inventory" << std::endl;
		return ;
	}
	if (this->inventory[idx] != NULL)
	{
		std::cout << this->name << " uses " << this->inventory[idx]->getType() << std::endl;
		this->inventory[idx]->use(target);
	}
	else
	{
		std::cerr << this->name << " tries to use empty inventory space (no action taken)" << std::endl;
	}
	return ;
}

Character	&Character::operator=(Character const &other)
{
	this->name = other.name;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
	}
	std::cout << "Character " << this->name << " copy assignement operator called" << std::endl;
	return (*this);
}
