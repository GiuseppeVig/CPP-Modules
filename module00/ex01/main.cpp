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
			if (myPhoneBook->index == 8)
				myPhoneBook->index = 0;
			add(myPhoneBook);
			myPhoneBook->index++;
		}
		else if (command == "SEARCH")
			search_phonebook(myPhoneBook);
		else if (command == "EXIT")
			break;
	}
	delete myPhoneBook;
	return (0);
}
