#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

std::string format_display(std::string str);

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

		void	add_info(std::string type, int i);
};

#endif
