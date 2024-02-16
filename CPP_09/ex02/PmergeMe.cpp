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

static clock_t initTime()
{
	return (std::clock());
}

static double getTime(const clock_t start)
{
	return (static_cast<double>(std::clock() - start) / 1000);
}

void PmergeMe::storeInVector(char **list)
{
	for (size_t index = 1; list[index]; index++)
	{
		if (!list[index][0] || !validInteger(list[index]))
			throw InvalidInteger(list[index]);
		this->_vector.push_back(atoi(list[index]));
	}
}

void PmergeMe::storeInDeque(char **list)
{
	for (size_t index = 1; list[index]; index++)
	{
		if (!list[index][0] || !validInteger(list[index]))
			throw InvalidInteger(list[index]);
		this->_deque.push_back(atoi(list[index]));
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
		this->_vectorPair.push_back(std::make_pair(*it, *(it + 1)));
	}
	this->_vector.clear();
}

void PmergeMe::storeInDequePair()
{
	for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); it += 2)
	{
		if (it + 1 == this->_deque.end())
		{
			this->_strayInt = *it;
			break;
		}
		this->_dequePair.push_back(std::make_pair(*it, *(it + 1)));
	}
	this->_deque.clear();
}

void PmergeMe::sortPairVector()
{
	for (std::vector< std::pair<int, int> >::iterator it = this->_vectorPair.begin(); it != this->_vectorPair.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::sortPairDeque()
{
	for (std::deque< std::pair<int, int> >::iterator it = this->_dequePair.begin(); it != this->_dequePair.end(); it++)
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

std::deque< std::pair<int, int> > PmergeMe::merge(std::deque< std::pair<int, int> > left, std::deque< std::pair<int, int> > right)
{
	std::deque< std::pair<int, int> > result;
	while (!left.empty() && !right.empty())
	{
		if (left.front().second <= right.front().second)
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
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

std::deque< std::pair<int, int> > PmergeMe::mergeSort(std::deque<std::pair<int, int> > dequePair)
{
	if (dequePair.size() < 2)
		return (dequePair);
	std::deque< std::pair<int, int> > left;
	std::deque< std::pair<int, int> > right;
	for (size_t index = 0; index < dequePair.size(); index++)
	{
		if (!(index % 2))
			left.push_back(dequePair[index]);
		else
			right.push_back(dequePair[index]);
	}
	left = mergeSort(left);
	right = mergeSort(right);
	return (merge(left, right));
}
void PmergeMe::fillIntoVector()
{
	size_t position = 0;
	size_t oldPosition = 0;
	size_t insertCount = 0;
	this->_vector.push_back(this->_vectorPair.front().first);
	for (std::vector< std::pair<int, int> >::iterator it = this->_vectorPair.begin(); it != this->_vectorPair.end(); ++it)
		this->_vector.push_back(it->second);
	for (size_t index = 0; index < this->_vector.size() - 1; index++)
	{
		position = (2 << index) - position;
		for (size_t index_j = position + oldPosition; index_j > oldPosition; index_j--)
		{
			if (insertCount == this->_vectorPair.size() - 1)
			{
				if (this->_strayInt >= 0)
					this->_vector.insert(std::upper_bound(this->_vector.begin(), this->_vector.end(), this->_strayInt),
						this->_strayInt);
				return;
			}
			if (index_j > this->_vectorPair.size() - 1)
				index_j = this->_vectorPair.size() - 1;
			this->_vector.insert(std::upper_bound(this->_vector.begin(), this->_vector.end(), this->_vectorPair[index_j].first),
				this->_vectorPair[index_j].first);
			insertCount++;
		}
		oldPosition += position;
	}
}

void PmergeMe::fillIntoDeque()
{
	size_t position = 0;
	size_t oldPosition = 0;
	size_t insertCount = 0;
	this->_deque.push_back(this->_dequePair.front().first);
	for (std::deque< std::pair<int, int> >::iterator it = this->_dequePair.begin(); it != this->_dequePair.end(); ++it)
		this->_deque.push_back(it->second);
	for (size_t index = 0; index < this->_deque.size() - 1; index++)
	{
		position = (2 << index) - position;
		for (size_t index_j = position + oldPosition; index_j > oldPosition; index_j--)
		{
			if (insertCount == this->_dequePair.size() - 1)
			{
				if (this->_strayInt >= 0)
					this->_deque.insert(std::upper_bound(this->_deque.begin(), this->_deque.end(), this->_strayInt),
						this->_strayInt);
				return;
			}
			if (index_j > this->_dequePair.size() - 1)
				index_j = this->_dequePair.size() - 1;
			this->_deque.insert(std::upper_bound(this->_deque.begin(), this->_deque.end(), this->_dequePair[index_j].first),
				this->_dequePair[index_j].first);
			insertCount++;
		}
		oldPosition += position;
	}
}


void PmergeMe::sortInVector(char **list)
{
	this->_vectorStart = initTime();
	storeInVector(list);
	if (this->_vector.empty())
		throw ListEmpty();
	printStartList();
	storeInVectorPair();
	sortPairVector();
	this->_vectorPair = mergeSort(this->_vectorPair);
	fillIntoVector();
	this->_vectorExecTime = getTime(this->_vectorStart);
}

void PmergeMe::sortInDeque(char **list)
{
	this->_dequeStart = initTime();
	storeInDeque(list);
	if (this->_deque.empty())
		throw ListEmpty();
	storeInDequePair();
	sortPairDeque();
	this->_dequePair = mergeSort(this->_dequePair);
	fillIntoDeque();
	this->_dequeExecTime = getTime(this->_dequeStart);
}

void PmergeMe::printStartList()
{
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != this->_vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printResult()
{
	std::cout << "After:  ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != this->_vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: "
		<< this->_vectorExecTime << "ms" << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: "
		<< this->_dequeExecTime << "ms" << std::endl;
}

const char *PmergeMe::ListEmpty::what()const throw()
{
	return ("Error: list is empty");
}

PmergeMe::InvalidInteger::~InvalidInteger() throw()
{}

PmergeMe::InvalidInteger::InvalidInteger(const std::string& arg) : _message("Error: '" + arg + "' is an invalid integer") {}

const char *PmergeMe::InvalidInteger::what() const throw()
{
	return (this->_message.c_str());
}