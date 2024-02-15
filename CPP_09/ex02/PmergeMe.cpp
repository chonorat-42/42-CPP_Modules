/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:17 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/15 19:37:34 by chonorat         ###   ########.fr       */
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
	size_t position = 2;
	size_t oldPosition = 0;
	size_t insertCount = 0;
	size_t oldIndex = 0;
	this->_vector.push_back(this->_vectorPair.front().first);
	for (std::vector< std::pair<int, int> >::iterator it = this->_vectorPair.begin(); it != this->_vectorPair.end(); it++)
		this->_vector.push_back(it->second);
	for (size_t index = 0; index < this->_vector.size() - 1; index++)
	{
		if (index != 0)
			oldPosition = position;
		position = (2 << index) - oldPosition;
		for (size_t index_j = position + oldIndex; index_j > oldIndex; index_j--)
		{
			if (insertCount == this->_vectorPair.size() - 1)
			{
				if (this->_strayInt >= 0)
					this->_vector.insert(std::lower_bound(this->_vector.begin(), this->_vector.end(), this->_strayInt), this->_strayInt);
				return;
			}
			if (index_j > this->_vectorPair.size() - 1)
				index_j = this->_vectorPair.size() - 1;
			this->_vector.insert(std::upper_bound(this->_vector.begin(), this->_vector.end(), this->_vectorPair[index_j].first), this->_vectorPair[index_j].first);
			insertCount++;
		}
		oldIndex += position;
	}
}

static void initTime(clock_t &time)
{
	time = clock();
}

void PmergeMe::sortInVector(char **list)
{
	initTime(this->vectorStart);
	storeInVector(list);
	if (this->_vector.empty())
		throw ListEmpty();
	printVectorStart();
	storeInVectorPair();
	sortPairVector();
	this->_vectorPair = mergeSort(this->_vectorPair);
	fillIntoContainer();
	printVectorResult();
}

static double getTime(clock_t start)
{
	return (static_cast<double>(std::clock() - start) / 1000);
}


void PmergeMe::printVectorStart()
{
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != this->_vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVectorResult()
{
	std::cout << "After:  ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != this->_vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: "
		<< getTime(this->vectorStart) << "ms" << std::endl;
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