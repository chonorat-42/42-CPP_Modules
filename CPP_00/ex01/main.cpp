/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:00 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/10 12:53:21 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	to_string(int number)
{
	std::string	result;

	while (number > 0)
	{
		const char digit = number % 10 + '0';
		result += digit;
		number /= 10;
	}
	return (result);
}

int	main()
{
	PhoneBook	directory;
	std::string	command;

	while (true)
	{
		std::cout << "ENTER COMMAND : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
		{
			if (!directory.addContact())
				return (0);
		}
		else if (command == "SEARCH")
		{
			if (!directory.searchContact())
				return (0);
		}
		else if (command == "EXIT")
			break;
	}
	return (0);
}
