/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:54 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/10 15:45:15 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void storeCSVData();
		void convertValuesFromFile(std::string fileName);

	private:
		std::map<std::string, double> _bitcoinData;
		char _CSVSeparator;
		void getCSVSeparator(std::string& line);
		bool storeInMap(std::string& line, size_t position);
		void exchangeValue(std::string& line, size_t position);
		void validBtcAmount(const std::string& btcAmount);
		void printResult(const std::string& date, float btcAmount);
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
		class CannotOpenFile : public std::exception
		{
			public:
				const char *what()const throw();
		};
		class BadInput : public std::exception
		{
			public:
				explicit BadInput(const std::string& input);
				~BadInput() throw();
				const char *what()const throw();
			private:
				std::string _message;
		};
		class NoDataFound : public std::exception
		{
			public:
				const char *what()const throw();
		};
		class NegativeValue : public std::exception
		{
			public:
				const char *what()const throw();
		};
		class ValueTooHigh : public std::exception
		{
			public:
				const char *what()const throw();
		};
};

#endif //BITCOINEXCHANGE_HPP
