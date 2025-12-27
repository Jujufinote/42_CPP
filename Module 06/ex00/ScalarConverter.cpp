#include "ScalarConverter.hpp"

long double	format(std::string str, long double& tmp)
{
	int	i = 0;
	int	is_ok = 0;

	if (str[0] == '+' || str[0] == '-')
		++i;
	for (i; i < str.length(); i++)
	{
		if (isdigit(str[i]) == 0 && str[i] != '.')
			return (1);
		if (str[i] == '.')
			is_ok++;
		if (is_ok > 1)
			return (1);
	}
	std::istringstream	isstr(str);
	isstr >> tmp; // long double conversion
	return (0);
}

int	convert_char(std::string str, long double& tmp)
{
	if (str.length() == 1 && isalpha(str[0]) != 0)
		tmp = str[0];
	else if (format(str, tmp) == 1 || tmp < 0)
		return (1);
	if (isprint(tmp) == 0)
		return (2);
	return (0);
}

int	convert_int(std::string str, long double& tmp)
{
	if (format(str, tmp) == 1)
		return (1);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (1);
	return (0);
}

int	convert_float(std::string str, long double& tmp)
{
	if (str == "+inf")
		return (2);
	if (str == "-inf")
		return (3);
	if (str == "nan")
		return (4);
	if (format(str, tmp) == 1)
		return (1);
	if (tmp < - FLT_MAX || tmp > FLT_MAX)
		return (1);
	return (0);
}

int	convert_double(std::string str, long double& tmp)
{
	if (str == "+inf")
		return (2);
	if (str == "-inf")
		return (3);
	if (str == "nan")
		return (4);
	if (format(str, tmp) == 1)
		return (1);
	if (tmp <  - DBL_MAX || tmp > DBL_MAX)
		return (1);
	return (0);
}

void	ScalarConverter::convert(std::string const& str)
{
	long double	tmp = 0;
	std::string	cpy_str;

	cpy_str = str;
	if (cpy_str.back() == 'f' && cpy_str != "+inf" && cpy_str != "-inf")
		cpy_str.pop_back();
	std::cout << "char: ";
	switch (convert_char(cpy_str, tmp))
	{
		case (1) :
		{
			std::cout << "impossible" << std::endl;
			break;
		}
		case (2) :
		{
			std::cout << "Non displayable" << std::endl;
			break;
		}
		default :
		{
			std::cout << "\'" << static_cast<char>(tmp) << "\'" << std::endl;
			break;
		}
	}

	std::cout << "int: ";
	switch (convert_int(cpy_str, tmp))
	{
		case (1) :
		{
			std::cout << "impossible" << std::endl;
			break;
		}
		default :
		{
			std::cout << static_cast<int>(tmp) << std::endl;
			break;
		}
	}

	std::cout << "float: ";
	switch (convert_float(cpy_str, tmp))
	{
		case (1) :
		{
			std::cout << "impossible" << std::endl;
			break;
		}
		case (2) :
		{
			std::cout << "+inf" << "f" << std::endl;
			break;
		}
		case (3) :
		{
			std::cout << "-inf" << "f" << std::endl;
			break;
		}
		case (4) :
		{
			std::cout << "nan" << "f" << std::endl;
			break;
		}
		default :
		{
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(tmp) << "f" << std::endl;
			break;
		}
	}

	std::cout << "double: ";
	switch (convert_double(cpy_str, tmp))
	{
		case (1) :
		{
			std::cout << "impossible" << std::endl;
			break;
		}
		case (2) :
		{
			std::cout << "+inf" << std::endl;
			break;
		}
		case (3) :
		{
			std::cout << "-inf" << std::endl;
			break;
		}
		case (4) :
		{
			std::cout << "nan" << std::endl;
			break;
		}
		default :
		{
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(tmp) << std::endl;
			break;
		}
	}
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const& copy)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& other)
{
	std::cout << "ScalarConverter copy assignement operator called" << std::endl;
	return (*this);
}

