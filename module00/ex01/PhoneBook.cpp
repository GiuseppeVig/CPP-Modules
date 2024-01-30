/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:19:05 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/30 14:43:29 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(void)
{
		std::cout<<"Goodbye"<<std::endl;
}

PhoneBook::PhoneBook(void){}

int	ft_digit(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	strlen(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void add(PhoneBook *phoneBook)
{
	char num[100];
	std::cout << "Give me the first name of the new contact" << std::endl;
	std::cin >> phoneBook->friends[phoneBook->index].first_name;
	std::cout << "Give me the last name of the new contact" << std::endl;
	std::cin >> phoneBook->friends[phoneBook->index].last_name;
	std::cout << "Give me the nickname of the new contact" << std::endl;
	std::cin >> phoneBook->friends[phoneBook->index].nickname;
	while (1)
	{
		std::cout << "Give me the phone_number of the new contact" << std::endl;
		std::cin >> num;
		if (ft_digit(num))
		{
			phoneBook->friends[phoneBook->index].phone_number = atoi(num);
			break;
		}
		else
			std::cout << "ERROR: Not a viable number" << std::endl;
	}
	std::cout << "Give me the darkest secret of the new contact" << std::endl;
	std::cin >> phoneBook->friends[phoneBook->index].darkest_secret;
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
	char j[1];
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
	if (atoi(j)  > myPhone->index + 1 || !ft_digit(j))
	{
		std::cout<<"ERROR: Invalid Index"<<std::endl;
		return;
	}
	print_list(myPhone, atoi(j) - 1);
}
