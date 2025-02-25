#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Contact
{
	private:
		std::string buffer;

	public:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;
		void	add_info(std::string type, int i)
		{
			std::cout << "\033[2J\033[1;1H";
			std::cout << "(" << ++i << "/8) Please enter contact information\n"
					  << type <<": ";
			std::getline(std::cin, buffer);
			if (buffer.empty())
			{
				add_info(type, i);
				return;
			}
			if (type == "First Name")
				first_name = buffer;
			else if (type == "Last Name")
				last_name = buffer;
			else if (type == "Nickname")
				nickname = buffer;
			else if (type == "Phone Number")
				phone_number = buffer;
			else if (type == "Dark Secret")
				dark_secret = buffer;
		}
};

std::string format_display(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

class PhoneBook
{
	private:
		std::string buffer;
	public:
		Contact contacts[8];
		// void	clear_contact(int i)
		// {
		// 	contacts[i].first_name = "";
		// 	contacts[i].last_name = "";
		// 	contacts[i].nickname = "";
		// 	contacts[i].phone_number = "";
		// 	contacts[i].dark_secret = "";
		// }
		void display_all_contacts()
		{
			int	j = 0;
			std::cout << std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << std::right << "First Name" << "|"
				<< std::setw(10) << std::right << "Last Name" << "|"
				<< std::setw(10) << std::right << "Nickname" << "\n";
			while (j < 7)
			{
				if (contacts[j].first_name.empty())
					return;
				std::cout << std::setw(10) << j + 1 << "|"
						  << std::setw(10) << std::right << format_display(contacts[j].first_name) << "|"
						  << std::setw(10) << std::right << format_display(contacts[j].last_name) << "|"
						  << std::setw(10) << std::right << format_display(contacts[j].nickname) << "|\n";
				j++;
			}
		}

		void	display_contact(int index)
		{
			std::cout << "First Name: " << contacts[index].first_name << "\n"
					  << "Last Name: " << contacts[index].last_name << "\n"
					  << "Nickname: " << contacts[index].nickname << "\n"
					  << "Phone Number: " << contacts[index].phone_number << "\n"
					  << "Dark Secret: " << contacts[index].dark_secret << "\n"
					  << "Press enter to continue: ";
					  getline(std::cin, buffer);
		}

		void	init_display_contact()
		{
			int index = 0;

			std::cout << "\nPlease enter the number of the entry you wish to display\n";
			getline(std::cin, buffer);
			std::cout << "\033[2J\033[1;1H";
			if (buffer == "1")
				display_contact(0);
			else if (buffer == "2")
				display_contact(1);
			else if (buffer == "3")
				display_contact(2);
			else if (buffer == "4")
				display_contact(3);
			else if (buffer == "5")
				display_contact(4);
			else if (buffer == "6")
				display_contact(5);
			else if (buffer == "7")
				display_contact(6);
			else if (buffer == "8")
				display_contact(7);
			else
			{
				init_display_contact();
				return;
			}
		}
};

int	main(void)
{
	bool	cont;
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
			//phonebook.clear_contact(i);
			phonebook.contacts[i].index = i;
			phonebook.contacts[i].add_info("First Name", i);
			phonebook.contacts[i].add_info("Last Name", i);
			phonebook.contacts[i].add_info("Nickname", i);
			phonebook.contacts[i].add_info("Phone Number", i);
			phonebook.contacts[i].add_info("Dark Secret", i);
			i++;
		}
		else if (input == "SEARCH")
		{
			phonebook.display_all_contacts();
			phonebook.init_display_contact();
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting...\n";
			exit(0);
		}
		else
		{
			std::cout << "Invalid input.\n";
		}
		std::cout << phonebook.contacts[i].first_name << "\n";
		std::cout << phonebook.contacts[i].last_name << "\n";
		std::cout << phonebook.contacts[i].nickname << "\n";
		std::cout << phonebook.contacts[i].phone_number << "\n";
		std::cout << phonebook.contacts[i].dark_secret << "\n";
		std::cout << "\033[2J\033[1;1H";
		if (i == 8)
			i = 0;
	}
	return 0;
}
