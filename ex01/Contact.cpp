#include "Contact.hpp"

void	Contact::add_info(std::string type, int i)
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << "(" << ++i << "/8) Please enter contact information\n"
			  << type <<": ";
	std::getline(std::cin, buffer);
	if (buffer.empty())
	{
		add_info(type, i - 1);
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
