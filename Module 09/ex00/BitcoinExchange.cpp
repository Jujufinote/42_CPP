#include "BitcoinExchange.hpp"

int	is_all_digit(std::string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (std::isdigit(str[i]) == 0)
			return 0;
	}
	return 1;
}

unsigned int	get_date(std::string line)
{
	std::string	year = line.substr(0, 4);
	std::string	month = line.substr(5, 2);
	std::string	day = line.substr(8, 2);

	if (is_all_digit(year) == 0 || is_all_digit(month) == 0 || is_all_digit(day) == 0)
		return 1;

	return (atoi(year.c_str()) * 10000 + atoi(month.c_str()) * 100 + atoi(day.c_str()));
}

float	get_value(std::string line, int pos, long long int max)
{
	std::string	value = line.substr(pos);
	int			is_ok = 0;
	int			i = 0;

	if (value[i] == '-')
		++i;
	for (i; i < value.length() ; ++i)
	{
		if ((std::isdigit(value[i]) == 0 && value[i] != '.') || is_ok > 1)
			return -1;
		if (value[i] == '.')
			is_ok++;
	}

	float	result = atof(value.c_str());
	if (result > max)
		return -3;
	else if (result < 0)
		return -2;
	return (result);
}

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;

	std::ifstream	ifd(DATA_PATH);
	if (!(ifd.is_open()))
	{
		throw std::runtime_error("Error opening data file");
	}

	std::string	line;
	std::getline(ifd, line); //pass first line
	while (1)
	{
		std::getline(ifd, line);
		if (ifd.eof() == true)
			break ;
		if (line.length() < 11 || line[4] != '-' || line[7] != '-' || line[10] != SEPARATOR)
			throw std::runtime_error("Error: bad input => " + line + ", format : date" + SEPARATOR + "exchange_rate");

		unsigned int	date = get_date(line);
		if (date == 1)
			throw std::runtime_error("Error: bad input => " + line + ", format : YYYY-MM-DD");

		float			value = get_value(line, 11, LLONG_MAX);
		if (value == -1)
			throw std::runtime_error("Error: bad input => " + line + ", exchange rate must be a positive number between 0 and 1000");
		else if (value == -2)
			throw std::runtime_error("Error: bad input => " + line + ", not a positive exchange rate.");
		else if (value == -3)
			throw std::runtime_error("Error: bad input => " + line + ", too large exchange rate.");

		this->_data[date] = value;
	}
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	this->_data = copy._data;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

std::map<unsigned int, float>::const_iterator	BitcoinExchange::searchDate(unsigned int date) const
{
	
	// search same date
	std::map<unsigned int, float>::const_iterator	it = this->_data.find(date);
	if (it != this->_data.end())
		return it;
	
	it = this->_data.begin();
	std::map<unsigned int, float>::const_iterator	now = this->_data.begin();

	// search inferior date
	for (now; now != this->_data.end(); now++)
	{
		if (now->first < date && now->first > it->first)
			it = now;
	}

	// give first date of history if inferior date in history not found
	return it;
}

void	BitcoinExchange::totalRate(std::string line) const
{
	// format
	if (line.length() < 12 || line[4] != '-' || line[7] != '-' || line[11] != '|')
	{
		std::cerr << "Error: bad input => " + line + ", format : date | value" << std::endl;
		return ;
	}

	// get date
	unsigned int	date = get_date(line);
	if (date == 1)
	{
		std::cerr << "Error: bad input => , format : YYYY-MM-DD" + line << std::endl;
		return ;
	}

	// get exchange rate
	std::map<unsigned int, float>::const_iterator	it = this->searchDate(date);
	float											exchange_rate = it->second;

	// get value
	float	value = get_value(line, 13, 1000);
	if (value == -1)
	{
		std::cerr << "Error: bad input => " + line + ", value must be a positive number between 0 and 1000" <<std::endl;
		return ;
	}
	else if (value == -2)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	else if (value == -3)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}

	// get string versions
	std::string	sdate = line.substr(0, 10);
	std::string	svalue = line.substr(13);

	std::cout << sdate + " => " + svalue + " = " << std::fixed << std::setprecision(2) << exchange_rate * value << std::endl; 
	return ;
}

/*---------------------------------------------------------------------------------------------------------------*/

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& other)
{
	std::cout << "BitcoinExchange copy assignement operator called" << std::endl;
	this->_data = other._data;
	return (*this);
}
