#ifndef CONTACT_CPP
# define CONTACT_CPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Contact {
	public:
		char first_name[100];
		char last_name[100];
		char nickname[100];
		int	phone_number;
		char darkest_secret[100];
		~Contact(void);
		Contact(void);
};

#endif
