/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:17 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/12 15:53:30 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{}

static bool validInteger(std::string arg)
{
	for (size_t index = 0; index < arg.size(); index++)
	{
		if (!isdigit(arg[index]))
			return (false);
	}
	if (atol(arg.c_str()) > INT_MAX)
		return (false);
	return (true);
}

void PmergeMe::storeInVector(char **list)
{
	for (size_t index = 1; list[index]; index++)
	{
		if (!validInteger(list[index]))
			throw InvalidInteger(list[index]);
		this->_vector.push_back(atoi(list[index]));
	}
}

void PmergeMe::sortInVector(char **list)
{
	storeInVector(list);
	this->_vec
}

const char *PmergeMe::ListEmpty::what()const throw()
{
	return ("Error: list is empty");
}

PmergeMe::InvalidInteger::~InvalidInteger() throw()
{}

PmergeMe::InvalidInteger::InvalidInteger(std::string arg) : _message("Error: '" + arg + "' is an invalid integer") {}

const char *PmergeMe::InvalidInteger::what() const throw()
{
	return (this->_message.c_str());
}