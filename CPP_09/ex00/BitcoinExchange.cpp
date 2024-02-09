/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:08:34 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/09 19:37:35 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->bitcoinData = other.bitcoinData;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	this->bitcoinData.clear();
}

static bool isLeapYear(int year)
{
	if (!(year % 400))
		return (true);
	if (!(year % 4))
	{
		if (year % 100)
			return (true);
	}
	return (false);
}

bool BitcoinExchange::validDate(const std::string& date)
{
	if (date.length() == 10)
	{
		const int year = atoi(date.substr(0, 4).c_str());
		const int month = atoi(date.substr(5, 2).c_str());
		const int day = atoi(date.substr(8, 2).c_str());
		const bool leapYear = isLeapYear(year);
		if (month < 1 || month > 12)
			return (false);
		if (day < 1 || day > 31)
			return (false);
		if (!leapYear && month == 2 && day > 28)
			return (false);
	}
	else
		return (false);
	return (true);
}

bool BitcoinExchange::validValue(const std::string &value)
{
	if (!value.empty())
	{
		char *end = NULL;
		double dtemp = strtod(value.c_str(), &end);
		if (dtemp < 0 || dtemp > 1000)
			return (false);
		if (end[0] || !isdigit(value[0]))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool BitcoinExchange::storeInMap(std::string& line, const size_t position)
{
	const size_t sepPos = line.find(',');
	if (sepPos != std::string::npos)
	{
		const std::string date = line.substr(0, sepPos);
		const std::string value = line.substr(sepPos + 1);
		if (!validDate(date) || !validValue(value))
		{
			if (position == 0)
				return (true);
			return (false);
		}
		this->bitcoinData[date] = static_cast<float>(strtod(value.c_str(), NULL));
		return (true);
	}
	return (false);
}

void BitcoinExchange::storeCSVData()
{
	std::ifstream infile("data.csv", std::ios::in);
	if (infile.is_open())
	{
		std::string line;
		size_t position = 0;
		while (std::getline(infile, line))
		{
			if (!storeInMap(line, position))
			{
				infile.close();
				throw CSVInvalidFormat();
			}
			position++;
		}
		std::cout << "value from 2021-07-25: " << this->bitcoinData["2021-07-25"] << std::endl;
		infile.close();
	}
	else
		throw CannotOpenCSV();
}

const char *BitcoinExchange::CannotOpenCSV::what() const throw()
{
	return ("Error: could not open data.csv.");
}

const char *BitcoinExchange::CSVInvalidFormat::what() const throw()
{
	return ("Error: invalid format in data.csv");
}
