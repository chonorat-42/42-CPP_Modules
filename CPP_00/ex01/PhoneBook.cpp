/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:38 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/10 14:08:21 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {index = 0;}

static bool	onlyWs(const std::string& str)
{
	for (size_t index = 0; index < str.length(); index++)
	{
		if (str[index] != ' ')
			return (false);
	}
	return (true);
}

static bool	validInput(const std::string& str)
{
	if (str.empty() || onlyWs(str))
		return (false);
	for (size_t index = 0; index < str.length(); index++)
	{
		if (!isprint(str[index]))
			return (false);
	}
	return (true);
}

int	PhoneBook::addContact()
{
	std::string	input;

	if (index == 8)
		index = 0;
	while (!validInput(input))
	{
		std::cout << "FIRST NAME : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	contact[index].addFirstName(input);
	input.clear();
	while (!validInput(input))
	{
		std::cout << "LAST NAME : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	contact[index].addLastName(input);
	input.clear();
	while (!validInput(input))
	{
		std::cout << "NICK NAME : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	contact[index].addNickName(input);
	input.clear();
	while (!validInput(input))
	{
		std::cout << "PHONE NUMBER : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	contact[index].addPhoneNumber(input);
	input.clear();
	while (!validInput(input))
	{
		std::cout << "DARKEST SECRET : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	contact[index].addSecret(input);
	contact[index].addIndex(index + 1);
	index++;
	return (1);
}

static void	printColumn(int count, std::string output)
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

void	PhoneBook::showContact(Contact contact)
{
	std::cout << "FIRST NAME : " << contact.getFirstName() << std::endl;
	std::cout << "LAST NAME : " << contact.getLastName() << std::endl;
	std::cout << "NICK NAME : " << contact.getNickName() << std::endl;
	std::cout << "PHONE NUMBER : " << contact.getPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET : " << contact.getSecret() << std::endl;
}

void	PhoneBook::contactPreview(int index)
{
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
}

int	PhoneBook::searchContact()
{
	int			index = 0;
	std::string	input;

	if (contact[0].getFirstName().empty())
	{
		std::cout << "NO CONTACT" << std::endl;
		return (1);
	}
	contactPreview(index);
	while (true)
	{
		std::cout << "ENTER INDEX : ";
		std::cin >> index;
		if (std::cin.eof())
			return (0);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index >= 1 && index <= 8)
		{
			if (contact[index - 1].getFirstName().empty())
				std::cout << "NO CONTACT FOUND" << std::endl;
			else
			{
				showContact(contact[index - 1]);
				break;
			}
		}
		else
			std::cout << "ENTER INDEX BETWEEN 1 AND 8" << std::endl;
	}
	return (1);
}
