#include "header.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created" << std::endl;
	return ;
}

Brain::Brain(Brain const &copy)
{
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain copied" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
	return ;
}

void	Brain::addIdea(std::string const idea)
{
	int i;

	i = 0;
	while (i < 100 && this->ideas[i].empty() == false)
	{
		++i;
	}
	this->ideas[i] = idea;
	std::cout << idea << " added to mind" << std::endl;
	return ;
}

void	Brain::display(void) const
{
	int i;

	i = 0;
	while (i < 100 && this->ideas[i].empty() == false)
	{
		std::cout << this->ideas[i] << std::endl;
		++i;
	}
	return ;
}

Brain	&Brain::operator=(Brain const &other)
{
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Copy assignement operator (Brain) called" << std::endl;
	return (*this);
}
