/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:42:46 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/22 16:38:59 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*upper(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= 'a' && str[j] <= 'z')
			str[j] -= 32;
		j++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "*LOUD MEGAPHONE NOISES*";
	}
	else
	{
		while (i < argc)
		{
			std::cout << upper(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
