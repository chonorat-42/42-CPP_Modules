/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/03 19:49:31 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {*this = other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool checkLiteral(const std::string& literal)
{
	char *endptr = NULL;

	strtod(literal.c_str(), &endptr);
	if (literal.length() == 1)
		return (true);
	if (!literal.compare("nan") || !literal.compare("nanf"))
		return (true);
	if (!literal.compare("inf") || !literal.compare("+inf") || !literal.compare("-inf"))
		return (true);
	if (!literal.compare("inff") || !literal.compare("+inff") || !literal.compare("-inff"))
		return (true);
	if (endptr[0])
	{
		if (strlen(endptr) > 1)
			return (false);
		if (endptr[0] != 'f')
			return (false);
		if (literal.find('f') != std::string::npos && literal.find('.') == std::string::npos)
			return (false);
	}
	return (true);
}

static void printResult(TypeData& data)
{
	std::cout << "char: ";
	if (data.getDoublePrecision() < 32 || data.getDoublePrecision() > 126)
		std::cout << "Non displayable" << std::endl;
	else if (isnan(data.getDoublePrecision()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << data.getCharacter() << "'" << std::endl;
	std::cout << "int: ";
	if (data.getDoublePrecision() > INT_MAX || data.getDoublePrecision() < INT_MIN)
		std::cout << "Overflow" << std::endl;
	else if (isnan(data.getDoublePrecision()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << data.getInteger() << std::endl;
	std::cout << "float: " << data.getFloating();
	if (data.getFloating() - static_cast<int>(data.getFloating()) == 0
			&& (data.getDoublePrecision() < 1000000 && data.getDoublePrecision() > -1000000))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << data.getDoublePrecision();
	if (data.getDoublePrecision() - static_cast<int>(data.getDoublePrecision()) == 0
			&& (data.getDoublePrecision() < 1000000 && data.getDoublePrecision() > -1000000))
		std::cout << ".0";
	std::cout << std::endl;
}

static void printAsChar(const char character)
{
	TypeData data(character, static_cast<int>(character), static_cast<float>(character), static_cast<double>(character));
	printResult(data);
}

static void printAsInt(const int integer)
{
	TypeData data(static_cast<char>(integer), integer, static_cast<float>(integer), static_cast<double>(integer));
	printResult(data);
}

static void printAsDouble(const double doubler)
{
	TypeData data(static_cast<char>(doubler), static_cast<int>(doubler), static_cast<float>(doubler), doubler);
	printResult(data);
}

static void printAsFloat(const float floating)
{
	TypeData data(static_cast<char>(floating), static_cast<int>(floating), floating, static_cast<double>(floating));
	printResult(data);
}

static bool checkOverflow(const std::string& literal)
{
	long longTemp = atol(literal.c_str());

	if (longTemp > INT_MAX || longTemp < INT_MIN)
		return (true);
	return (false);
}

static void detectType(const std::string& literal)
{
	if (literal.find('f') != std::string::npos && literal.length() > 1)
		return (printAsFloat(atof(literal.c_str())));
	if (literal.find('.') != std::string::npos || checkOverflow(literal)
			|| !literal.compare("nan") || !literal.compare("-nan") || !literal.compare("+nan"))
		return (printAsDouble(strtod(literal.c_str(), NULL)));
	if (literal.length() == 1 && ((literal.c_str()[0] >= 32 && literal.c_str()[0] < 48)
			|| (literal.c_str()[0] > 57 && literal.c_str()[0] <= 126)))
		return (printAsChar(literal.c_str()[0]));
	printAsInt(atoi(literal.c_str()));
}

void ScalarConverter::convert(std::string literal)
{
	if (!checkLiteral(literal))
		throw ImpossibleConversion();
	detectType(literal);
}

const char *ScalarConverter::ImpossibleConversion::what() const throw()
{
	return ("impossible conversion");
}

