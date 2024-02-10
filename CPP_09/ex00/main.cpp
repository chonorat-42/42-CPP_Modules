/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:23:43 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/10 15:48:31 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(const int argc, char *argv[])
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange data;
			data.storeCSVData();
			data.convertValuesFromFile(argv[1]);
		}
		catch (std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Usage: ./btc \'file_name\'" << std::endl;
		return (1);
	}
	return (0);
}
