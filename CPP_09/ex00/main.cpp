/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:23:43 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/09 13:05:30 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool validFile(const std::string& file)
{
	if (!file.empty())
	{
		if (file.find(".txt") != std::string::npos && file[0] != '.')
			return (true);
	}
	return (false);
}

int main(const int argc, char *argv[])
{
	if (argc == 2 && validFile(argv[1]))
	{
		try
		{
			BitcoinExchange data;
			data.storeCSVData();
		}
		catch (std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Usage: ./btc \'input.txt\'" << std::endl;
		return (1);
	}
	return (0);
}