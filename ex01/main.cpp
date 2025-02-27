#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string format_display(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int	main(void)
{
	std::string	input;
	std::string	buffer;
	int	i;

	i = 0;
	PhoneBook phonebook;
	std::cout << "\033[2J\033[1;1H";
	std::cout << "Welcome to your PhoneBook!\n\n\n\n"
			  << "Press enter to continue: ";
	getline(std::cin, buffer);
	std::cout << "\033[2J\033[1;1H";
	while (1)
	{
		std::cout << "To proceed please enter one of the following commands:\n"
				<< "ADD - add a contact\n"
				<< "SEARCH - search for a contact\n"
				<< "Exit\n"
				<< ">> ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phonebook.contacts[i].index = i;
			phonebook.contacts[i].add_info("First Name", i);
			phonebook.contacts[i].add_info("Last Name", i);
			phonebook.contacts[i].add_info("Nickname", i);
			phonebook.contacts[i].add_info("Phone Number", i);
			phonebook.contacts[i].add_info("Dark Secret", i);
			i++;
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH")
		{
			phonebook.display_all_contacts();
			phonebook.init_display_single_contact();
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting...\n";
			exit(0);
		}
		else
			std::cout << "Invalid input.\n";
		std::cout << "\033[2J\033[1;1H";
	}
	return 0;
}
