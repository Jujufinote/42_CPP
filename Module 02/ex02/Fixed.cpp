# include "header.hpp"

int const	Fixed::bits = 8;

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.value < b.value)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.value < b.value)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.value < b.value)
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.value < b.value)
		return (b);
	return (a);
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
	return ;
}

Fixed::Fixed(int const nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = nb << this->bits;
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(nb * (1 << this->bits));
	return ;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = copy.value;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fonction called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
	return ;
}

int		Fixed::toInt(void) const
{
	int		i_nb;

	i_nb = this->value >> this->bits;
	return (i_nb);
}

float	Fixed::toFloat(void) const
{
	float	f_nb;

	f_nb = (float)this->value / (1 << this->bits);
	return (f_nb);
}

bool	Fixed::operator>(Fixed const &other) const
{
	return (this->value > other.value);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->value < other.value);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->value <= other.value);
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->value != other.value); 
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = other.value;
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed old(*this);
	this->operator++();
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed old(*this);
	this->operator--();
	return (old);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &other)
{
	o << other.toFloat();
	return o;
}
