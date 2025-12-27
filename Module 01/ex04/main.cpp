#include "header.hpp"

//!C file manipulation fonctions forbidden

int	main(int ac, char**av)
{
	if (ac != 4)
	{
		std::cout << "Usage : <filename> <s1> <s2>\n\tGive a file in which you want to replace s1 by s2\n" << std::endl;
		return 1;
	}
	
	int				length;
	std::string		file = av[1];
	std::ifstream	ifd(file);
	std::string	s1 = av[2];
	std::string s2 = av[3];
	
	if (!(ifd.is_open()))
	{
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}
	
	// caughting the length
	ifd.seekg(0, ifd.end); // go to end
	length = ifd.tellg(); // return position
	ifd.seekg(0, ifd.beg); // got to beginning
	
	// creating a buffer of length size and fill it with \0
	size_t		p = 0; // position
	std::string	buf(length, '\0');

	// reading and copying in buffer
	ifd.read(&buf[0], length);

	// replace strings
	while ((p = buf.find(s1, p)) != std::string::npos)
	{
		buf.erase(p, s1.length());
		buf.insert(p, s2);
		p += s2.length();
	}

	// erase the remainning \0 in buffer
	int	i = buf.length() - 1;
	while (buf[i] == '\0')
	{
		--i;
	}
	buf = buf.substr(0, i + 1);

	// name creation
	std::string		name;
	if (file.rfind(".") == std::string::npos)
	{
		name =  file.substr(0, file.length()) + ".replace";
	}
	else
	{
		name = file.substr(0, file.rfind(".")) + ".replace" + file.substr(file.rfind("."));
	}

	std::ofstream	ofd(name);

	if (!(ofd.is_open()))
	{
		std::cerr << "Error creating file" << std::endl;
		return 1;
	}

	// fill the replacement file
	ofd << buf;

	return 0;
}
