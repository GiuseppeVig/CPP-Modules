#ifndef CONTACT_CPP
# define CONTACT_CPP

class Contact {
	public:
		char first_name[100];
		char last_name[100];
		char nickname[100];
		long	phone_number;
		char darkest_secret[100];
		~Contact();
};

#endif
