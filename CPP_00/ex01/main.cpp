/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:00 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/20 23:51:37 by chonorat         ###   ########.fr       */
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
			directory.addContact();
		else if (command == "SEARCH")
			directory.searchContact();
		else if (command == "EXIT")
			break;
	}
	return (EXIT_SUCCESS);
}
