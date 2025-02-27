#include "PhoneBook.hpp"

void PhoneBook::display_all_contacts()
		{
			int	j = 0;
			std::cout << std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << std::right << "First Name" << "|"
				<< std::setw(10) << std::right << "Last Name" << "|"
				<< std::setw(10) << std::right << "Nickname" << "\n";
			while (j < 8)
			{
				std::cout << std::setw(10) << j + 1 << "|"
						  << std::setw(10) << std::right << format_display(contacts[j].first_name) << "|"
						  << std::setw(10) << std::right << format_display(contacts[j].last_name) << "|"
						  << std::setw(10) << std::right << format_display(contacts[j].nickname) << "|\n";
				j++;
			}
		}

void	PhoneBook::display_single_contact(int index)
{
	std::cout << "First Name: " << contacts[index].first_name << "\n"
				<< "Last Name: " << contacts[index].last_name << "\n"
				<< "Nickname: " << contacts[index].nickname << "\n"
				<< "Phone Number: " << contacts[index].phone_number << "\n"
				<< "Dark Secret: " << contacts[index].dark_secret << "\n"
				<< "Press enter to continue: ";
				getline(std::cin, buffer);
}

void	PhoneBook::init_display_single_contact()
{
	int index = 0;

	std::cout << "\nPlease enter the number of the entry you wish to display (1-8)\n";
	getline(std::cin, buffer);
	std::cout << "\033[2J\033[1;1H";
	if (buffer == "1")
		display_single_contact(0);
	else if (buffer == "2")
		display_single_contact(1);
	else if (buffer == "3")
		display_single_contact(2);
	else if (buffer == "4")
		display_single_contact(3);
	else if (buffer == "5")
		display_single_contact(4);
	else if (buffer == "6")
		display_single_contact(5);
	else if (buffer == "7")
		display_single_contact(6);
	else if (buffer == "8")
		display_single_contact(7);
	else
	{
		display_all_contacts();
		init_display_single_contact();
		return;
	}
}
