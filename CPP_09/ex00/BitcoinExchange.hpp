/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:54 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/09 19:20:37 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void storeCSVData();

	private:
		std::map<std::string, float> bitcoinData;
		bool storeInMap(std::string& line, size_t position);
		bool validDate(const std::string& date);
		bool validValue(const std::string& value);
		class CannotOpenCSV : public std::exception
		{
			public:
				const char *what()const throw();
		};
		class CSVInvalidFormat : public std::exception
		{
			public:
				const char *what()const throw();
		};
};

#endif //BITCOINEXCHANGE_HPP
