#include "header.hpp"

PhoneBook::PhoneBook(void)
{
	this->i = 0;
	return ;
}

void	PhoneBook::add(Contact contact)
{
	this->tablo[i] = contact;
	this->i++;
	if (this->i == 8)
		this->i = 0;
	return ;
}

void	PhoneBook::printphonebook(void)
{
	std::cout << "\t|" << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "\t|" << std::setw(10) << i + 1 << "|";
		is_too_long(this->tablo[i].getFname());
		is_too_long(this->tablo[i].getLname()); 
		is_too_long(this->tablo[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::search(int index)
{
	if (this->tablo[index].getFname() == "")
	{
		std::cout << "\tEmpty contact" << std::endl;
	}
	else
	{
		std::cout << "\tFirst name     : " << this->tablo[index].getFname() << std::endl;
		std::cout << "\tLast name      : " << this->tablo[index].getLname() << std::endl;
		std::cout << "\tNickname       : " << this->tablo[index].getNickname() << std::endl;
		std::cout << "\tNumber         : " << this->tablo[index].getNum() << std::endl;
		std::cout << "\tDeepest secret : " << this->tablo[index].getSecret() << std::endl;
	}
	std::cout << std::endl;
	return ;
}
