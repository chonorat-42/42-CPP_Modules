/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:38 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 18:00:38 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

std::string	to_string(int number)
{
	char		digit;
	std::string	result;

	while (number > 0)
	{
		digit = number % 10 + '0';
		result += digit;
		number /= 10;
	}
	return (result);
}

int	PhoneBook::addContact()
{
	std::string	input;

	if (index == 8)
		index = 0;
	std::cout << "FIRST NAME : ";
	std::cin >> input;
	if (std::cin.eof())
		return (0);
	contact[index].addFirstName(input);
	std::cout << "LAST NAME : ";
	std::cin >> input;
	if (std::cin.eof())
		return (0);
	contact[index].addLastName(input);
	std::cout << "NICK NAME : ";
	std::cin >> input;
	if (std::cin.eof())
		return (0);
	contact[index].addNickName(input);
	std::cout << "PHONE NUMBER : ";
	std::cin >> input;
	if (std::cin.eof())
		return (0);
	contact[index].addPhoneNumber(input);
	std::cout << "DARKEST SECRET : ";
	std::cin >> input;
	if (std::cin.eof())
		return (0);
	contact[index].addSecret(input);
	contact[index].addIndex(index + 1);
	index++;
	return (1);
}

void	printColumn(int count, std::string output)
{
	if (count < 0)
	{
		output = output.substr(0, 9);
		output.push_back('.');
	}
	while (count > 0)
	{
		std::cout << ' ';
		count--;
	}
	std::cout << output << '|';
}

void	showContact(Contact contact)
{
	std::cout << "FIRST NAME : " << contact.getFirstName() << std::endl;
	std::cout << "LAST NAME : " << contact.getLastName() << std::endl;
	std::cout << "NICK NAME : " << contact.getNickName() << std::endl;
	std::cout << "PHONE NUMBER : " << contact.getPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET : " << contact.getSecret() << std::endl;
}

int	PhoneBook::searchContact()
{
	int			index = 0;
	std::string	input;

	if (contact[0].getFirstName().length() == 0)
	{
		std::cout << "NO CONTACT" << std::endl;
		return (1);
	}
	while (index < 8 && contact[index].getFirstName().length())
	{
		std::cout << '|';
		printColumn(10 - contact[index].getIndex().length(), contact[index].getIndex());
		printColumn(10 - contact[index].getFirstName().length(), contact[index].getFirstName());
		printColumn(10 - contact[index].getLastName().length(), contact[index].getLastName());
		printColumn(10 - contact[index].getNickName().length(), contact[index].getNickName());
		std::cout << std::endl;
		index++;
	}
	std::cout << "ENTER INDEX : ";
	std::cin >> index;
	if (std::cin.eof())
		return (0);
	if (index >= 1 && index <= 8)
	{
		if (contact[index - 1].getFirstName().length() == 0)
			std::cout << "NO CONTACT FOUND" << std::endl;
		else
			showContact(contact[index - 1]);
	}
	else
		std::cout << "ENTER INDEX BETWEEN 1 AND 8" << std::endl;
	return (1);
}
