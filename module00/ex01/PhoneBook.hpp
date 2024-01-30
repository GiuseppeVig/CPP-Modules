#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact friends[8];
		int index;
		~PhoneBook(void);
		PhoneBook(void);
};

int	strlen(std::string str);
void add(PhoneBook *phoneBook);
void	print_list(PhoneBook *myPhone, int i);
void	search_phonebook(PhoneBook *myPhone);

#endif
