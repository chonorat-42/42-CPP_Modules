/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:17 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/14 16:35:49 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->_vector.clear();
	this->_vectorPair.clear();
	this->_strayInt = -1;
}

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
{
	this->_vector.clear();
	this->_vectorPair.clear();
}

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

void PmergeMe::storeInVectorPair()
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it += 2)
	{
		if (it + 1 == this->_vector.end())
		{
			this->_strayInt = *it;
			break;
		}
		else
			this->_vectorPair.push_back(std::make_pair(*it, *(it + 1)));
	}
	this->_vector.clear();
}

void PmergeMe::sortPairVector()
{
	for (std::vector< std::pair<int, int> >::iterator it = this->_vectorPair.begin(); it != this->_vectorPair.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

std::vector< std::pair<int, int> > PmergeMe::merge(std::vector< std::pair<int, int> > left, std::vector< std::pair<int, int> > right)
{
	std::vector< std::pair<int, int> > result;

	while (!left.empty() && !right.empty())
	{
		if (left.front().second <= right.front().second)
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return (result);
}

std::vector< std::pair<int, int> > PmergeMe::mergeSort(std::vector<std::pair<int, int> > vectorPair)
{
	if (vectorPair.size() < 2)
		return (vectorPair);
	std::vector< std::pair<int, int> > left;
	std::vector< std::pair<int, int> > right;
	for (size_t index = 0; index < vectorPair.size(); index++)
	{
		if (!(index % 2))
			left.push_back(vectorPair[index]);
		else
			right.push_back(vectorPair[index]);
	}
	left = mergeSort(left);
	right = mergeSort(right);
	return (merge(left, right));
}

void PmergeMe::fillIntoContainer()
{
	this->_vector.push_back(this->_vectorPair.front().first);
	for (std::vector< std::pair<int, int> >::iterator it = this->_vectorPair.begin(); it != this->_vectorPair.end(); it++)
		this->_vector.push_back(it->second);

}

void PmergeMe::sortInVector(char **list)
{
	storeInVector(list);
	if (this->_vector.empty())
		throw ListEmpty();
	storeInVectorPair();
	sortPairVector();
	this->_vectorPair = mergeSort(this->_vectorPair);
	fillIntoContainer();
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