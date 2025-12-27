#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream> // cout, endl
# include <sstream> // istringstream (conversion ldouble)
# include <iomanip> // setprecision
# include <string> // string
# include <climits> // INT_MIN, INT_MAX
# include <cfloat> // FLT_MAX, DBL_MAX
# include <cctype> // isdigit

class ScalarConverter
{
	private :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& copy);
		ScalarConverter&	operator=(ScalarConverter const& other);

	public :
		virtual ~ScalarConverter(void);

		static void			convert(std::string const& parameter);

};

#endif
