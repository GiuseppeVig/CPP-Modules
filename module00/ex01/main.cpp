#include "PhoneBook.hpp"

int	main()
{
	PhoneBook *myPhoneBook = new PhoneBook();
	std::string command;
	myPhoneBook->index = 0;
	while (1)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			Contact	*contact = add();
			if (myPhoneBook->index == 8)
				myPhoneBook->index = 0;
			myPhoneBook->friends[myPhoneBook->index++] = *contact;
			delete contact;
		}
		else if (command == "SEARCH")
			search_phonebook(myPhoneBook);
		else if (command == "EXIT")
			break;
	}
	delete myPhoneBook;
	std::cout<<"Goodbye"<<std::endl;
	return (0);
}