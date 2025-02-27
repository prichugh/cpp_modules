#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		std::string buffer;
	public:
		Contact contacts[8];
		//void add_contact();
		void display_all_contacts();
		void display_single_contact(int index);
		void init_display_single_contact();

	};

#endif
