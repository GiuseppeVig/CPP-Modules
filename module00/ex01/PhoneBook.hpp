#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
	public:
		Contact friends[8];
		int index;
		~PhoneBook(){
		};
};

#endif
