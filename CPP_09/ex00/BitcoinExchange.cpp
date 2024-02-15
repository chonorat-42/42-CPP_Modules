/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:08:34 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/10 16:10:28 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->_bitcoinData.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	this->_bitcoinData.clear();
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

static bool validDate(const std::string& date)
{
	if (date.length() == 10)
	{
		const int year = atoi(date.substr(0, 4).c_str());
		const int month = atoi(date.substr(5, 2).c_str());
		const int day = atoi(date.substr(8, 2).c_str());
		if (year < 1000 || year > 9999)
			return (false);
		if (month < 1 || month > 12)
			return (false);
		if (day < 1 || day > 31)
			return (false);
		if (month <= 7 && !(month % 2) && day > 30)
			return (false);
		if (month >= 8 && month % 2 && day > 30)
			return (false);
		if (month == 2 && day > 28)
		{
			if (isLeapYear(year) && day == 29)
				return (true);
			return (false);
		}
	}
	else
		return (false);
	return (true);
}

static bool validValue(const std::string &value)
{
	if (!value.empty())
	{
		char *end = NULL;
		strtod(value.c_str(), &end);
		if (end[0] || !isdigit(value[0]))
			return (false);
	}
	else
		return (false);
	return (true);
}

void BitcoinExchange::validBtcAmount(const std::string& btcAmount)
{
	if (!btcAmount.empty())
	{
		char *end = NULL;
		const double dtemp = strtod(btcAmount.c_str(), &end);
		if (end[0])
			throw BadInput(btcAmount);
		if (dtemp < 0)
			throw NegativeValue();
		if (dtemp > 1000)
			throw ValueTooHigh();
	}
	else
		throw BadInput(btcAmount);
}

bool BitcoinExchange::storeInMap(std::string& line, const size_t position)
{
	if (position == 0)
		return (true);
	const size_t sepPos = line.find(',');
	if (sepPos != std::string::npos)
	{
		const std::string date = line.substr(0, sepPos);
		const std::string value = line.substr(sepPos + 1);
		if (!validDate(date) || !validValue(value))
			return (false);
		this->_bitcoinData[date] = strtod(value.c_str(), NULL);
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
		infile.close();
	}
	else
		throw CannotOpenCSV();
}

void BitcoinExchange::printResult(const std::string &date, const float btcAmount)
{
	std::cout << date << " => " << btcAmount << " = ";
	if (this->_bitcoinData.find(date) != this->_bitcoinData.end())
		std::cout << btcAmount * this->_bitcoinData[date] << std::endl;
	else
	{
		std::map<std::string, double>::iterator it = this->_bitcoinData.lower_bound(date);
		if (it != this->_bitcoinData.begin())
			std::cout << btcAmount * (--it)->second << std::endl;
		else
			throw NoDataFound();
	}
}

void BitcoinExchange::exchangeValue(std::string &line, const size_t position)
{
	if (position == 0)
		return;
	const size_t sepPos = line.find(" | ");
	if (sepPos != std::string::npos)
	{
		std::string date = line.substr(0, sepPos);
		std::string btcAmount = line.substr(sepPos + 3);
		if (!validDate(date))
			throw BadInput(date);
		validBtcAmount(btcAmount);
		printResult(date, static_cast<float>(strtod(btcAmount.c_str(), NULL)));
	}
	else
		throw BadInput(line);
}

void BitcoinExchange::convertValuesFromFile(std::string fileName)
{
	std::ifstream infile(fileName.c_str(), std::ios::in);
	if (infile.is_open())
	{
		std::string line;
		size_t position = 0;
		while (std::getline(infile, line))
		{
			try
			{
				if (!line.empty())
					exchangeValue(line, position);
			}
			catch (std::exception& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			position++;
		}
		infile.close();
	}
	else
		throw CannotOpenFile();
}

const char *BitcoinExchange::CannotOpenCSV::what() const throw()
{
	return ("Error: could not open data.csv.");
}

const char *BitcoinExchange::CSVInvalidFormat::what() const throw()
{
	return ("Error: invalid format in data.csv.");
}

const char *BitcoinExchange::CannotOpenFile::what() const throw()
{
	return ("Error: could not open file.");
}

BitcoinExchange::BadInput::BadInput(const std::string& input) : _message("Error: bad input => " + input) {}

BitcoinExchange::BadInput::~BadInput() throw() {}

const char *BitcoinExchange::BadInput::what() const throw()
{
	return (_message.c_str());
}

const char *BitcoinExchange::NoDataFound::what() const throw()
{
	return ("no Bitcoin exchange rate found for this date or previous date.");
}

const char *BitcoinExchange::NegativeValue::what() const throw()
{
	return ("Error: not a positive number.");
}

const char *BitcoinExchange::ValueTooHigh::what() const throw()
{
	return ("Error: too large a number.");
}