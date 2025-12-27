#include "header.hpp"

void	is_too_long(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << std::setw(10) << str.substr(0, 9) + "." << "|";
	}
	else
	{
		std::cout << std::setw(10) << str << "|";
	}
	return ;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	arg;
	std::string temp;
	int			is_ok;

	std::cout << "\n\t\tPhoneBook :\n\n Commands available : ADD, SEARCH, EXIT\n" << std::endl;
	while (1)
	{
		std::cout << "? : ";
		std::cin >> arg;
		std::cout << std::endl;
		if (arg == "add" || arg == "search" || arg == "exit")
			std::cout << "\tCommands must be written in caps\n" << std::endl;
		else if (arg == "ADD")
		{
			Contact contact;

			std::cout << "\tFirst name ? : ";
			std::cin >> temp;
			contact.setFname(temp);
			std::cout << "\tLast name ? : ";
			std::cin >> temp;
			contact.setLname(temp);
			std::cout << "\tNickname ? : ";
			std::cin >> temp;
			contact.setNickname(temp);
			is_ok = 0;
			while (is_ok == 0)
			{
				std::cout << "\tPhone number ? : ";
				std::cin >> temp;
				contact.setNum(temp);
				std::cout << std::endl;
				for (int i = 0; i < contact.getNum().length(); i++)
				{
					if (std::isdigit(contact.getNum()[i]) == 0)
					{
						is_ok = 0;
						break;
					}
					else
						is_ok = 1;
				}
				if (is_ok == 0)
					std::cout << "\t\tMust be all digits\n" << std::endl;
				else
				{
					is_ok = 0;
					if (contact.getNum().length() < 11)
						is_ok = 1;
					if (is_ok == 0)
						std::cout << "\t\tNumber not in the right format\n" << std::endl;
				}
			}
			std::cout << "\tDeepest secret ? : ";
			std::cin >> temp;
			contact.setSecret(temp);
			std::cout << std::endl;
			phonebook.add(contact);
		}
		else if (arg == "SEARCH")
		{
			phonebook.printphonebook();
			is_ok = 0;
			while (is_ok == 0)
			{
				std::cout << "    Index ? (you can quit with : QUIT) : ";
				std::cin >> arg;
				std::cout << std::endl;
				if (arg == "QUIT")
					break;
				for (int i = 0; i < arg.length(); i++)
				{
					if (std::isdigit(arg[i]) == 0)
					{
						is_ok = 0;
						break;
					}
					else
						is_ok = 1;
				}
				if (is_ok == 0)
					std::cout << "\tMust be a digit\n" << std::endl;
				else
				{
					is_ok = 0;
					if (arg.length() == 1)
					{
						if (arg[0] > '0' && arg[0] < '9')
							is_ok = 1;
					}
					if (is_ok == 0)
						std::cout << "\tGiven index isn't in PhoneBook\n" << std::endl;
				}
			}
			if (arg != "QUIT")
				phonebook.search(arg[0] - 49);
		}
		else if (arg == "EXIT")
		{
			break ;
		}
	}
	return 0;
}
