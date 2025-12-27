#include "header.hpp"

std::string const Contact::getFname(void) const
{
	return (this->fname);
}

std::string const Contact::getLname(void) const
{
	return (this->lname);
}

std::string const Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string const Contact::getNum(void) const
{
	return (this->num);
}

std::string const Contact::getSecret(void) const
{
	return (this->secret);
}

void	Contact::setFname(std::string str)
{
	this->fname = str;
	return ;
}

void	Contact::setLname(std::string str)
{
	this->lname = str;
	return ;
}

void	Contact::setNickname(std::string str)
{
	this->nickname = str;
	return ;
}

void	Contact::setNum(std::string str)
{
	this->num = str;
	return ;
}

void	Contact::setSecret(std::string str)
{
	this->secret = str;
	return ;
}
