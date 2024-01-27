/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:19:05 by gvigilan          #+#    #+#             */
/*   Updated: 2023/11/23 23:24:49 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "PhoneBook.hpp"

int	strlen(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

PhoneBook::~PhoneBook(void){}

PhoneBook::PhoneBook(void){}

Contact* add()
{
	Contact	*contact=new Contact();
	std::cout << "Give me the first name of the new contact" << std::endl;
	std::cin >> contact->first_name;
	std::cout << "Give me the last name of the new contact" << std::endl;
	std::cin >> contact->last_name;
	std::cout << "Give me the nickname of the new contact" << std::endl;
	std::cin >> contact->nickname;
	std::cout << "Give me the phone_number of the new contact" << std::endl;
	std::cin >> contact->phone_number;
	std::cout << "Give me the darkest secret of the new contact" << std::endl;
	std::cin >> contact->darkest_secret;
	return (contact);
}

void	print_list(PhoneBook *myPhone, int i)
{
	std::cout<<"        "<< i<<"|";
	if(strlen(myPhone->friends[i].first_name) > 10)
		{
			for(int j = 0; j < 9; j++)
				std::cout<<myPhone->friends[i].first_name[i];
			std::cout<<".|";
		}
	else
		{
			for(int j = 0; strlen(myPhone->friends[i].first_name) + j < 10; j++)
				std::cout<<" ";
			std::cout<<myPhone->friends[i].first_name<<".|";
		}
	if(strlen(myPhone->friends[i].last_name) > 10)
		{
			for(int j = 0; j < 9; j++)
				std::cout<<myPhone->friends[i].last_name[i];
			std::cout<<".|";
		}
	else
		{
			for(int j = 0; strlen(myPhone->friends[i].last_name) + j < 10; j++)
				std::cout<<" ";
			std::cout<<myPhone->friends[i].last_name<<".|";
		}
	if(strlen(myPhone->friends[i].nickname) > 10)
		{
			for(int j = 0; j < 9; j++)
				std::cout<<myPhone->friends[i].nickname[i];
			std::cout<<"."<<std::endl;
		}
	else
		{
			for(int j = 0; strlen(myPhone->friends[i].nickname) + j < 10; j++)
				std::cout<<" ";
			std::cout<<myPhone->friends[i].nickname<<std::endl;
		}
}

void	search_phonebook(PhoneBook *myPhone)
{
	int j;
	if (myPhone->index == 0)
	{
		std::cout << "You have no friends" << std::endl;
		return;
	}
	std::cout << "Here's your list of friends: " << std::endl;
	for (int i = 0; i < myPhone->index; i++)
		print_list(myPhone, i);
	std::cout << "Choose an index" << std::endl;
	std::cin >> j;
	if (j < myPhone->index)
		print_list(myPhone, j);
	else
		std::cout<<"Invalid Index! Either the contact doesn't exist or it's out of range"<<std::endl;
}
