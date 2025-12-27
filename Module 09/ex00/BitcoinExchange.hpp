#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <cctype>
# include <climits>
# include <cstdlib>
# include <map>

# define DATA_PATH "data.csv"
# define SEPARATOR ','

class BitcoinExchange
{
	private :
		std::map<unsigned int, float>	_data;

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const& copy);
		virtual ~BitcoinExchange(void);

		std::map<unsigned int, float>::const_iterator	searchDate(unsigned int date) const;
		void											totalRate(std::string line) const;

		BitcoinExchange&								operator=(BitcoinExchange const& other);
};

#endif
