/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/02 17:53:52 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {*this = other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool checkLiteral(std::string& literal)
{
	char *endptr;
	double d = strtod(literal.c_str(), &endptr);

	std::cout << d << std::endl;
	std::cout << endptr << std::endl;
	std::cout << d << std::endl;
	if (endptr && (strlen(endptr) > 1 || endptr[0] != 'f'))
		return (false);
	return (true);
}

void ScalarConverter::convert(std::string literal)
{
	std::cout << checkLiteral(literal) << std::endl;
}

