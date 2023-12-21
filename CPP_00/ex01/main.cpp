/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:00 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 17:59:50 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	directory;
	std::string	command;

	while (true)
	{
		std::cout << "ENTER COMMAND : ";
		std::cin >> command;
		if (std::cin.eof())
			break;
		else if (command == "ADD")
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
