/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:35:38 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/07 17:57:36 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->elementCount = 0;
	this->listSize = 0;
}

Span::Span(const unsigned int max)
{
	this->listSize = max;
	this->elementCount = 0;
}

Span::Span(const Span &other)
{
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->elementCount = other.elementCount;
		this->listSize = other.listSize;
		this->list = other.list;
	}
	return (*this);
}

Span::~Span()
{
	this->list.clear();
}

void Span::addNumber(const int integer)
{
	if (this->elementCount < this->listSize)
	{
		this->list.push_back(integer);
		this->elementCount++;
	}
	else
		throw SpanException();
}

void Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	if (this->elementCount + std::distance(begin, end) <= this->listSize)
	{
		this->list.insert(this->list.end(), begin, end);
		this->elementCount += std::distance(begin, end);
	}
	else
		throw SpanException();
}


size_t Span::longestSpan()
{
	if (this->elementCount > 1)
	{
		std::sort(this->list.begin(), this->list.end());
		return (*(--this->list.end()) - *this->list.begin());
	}
	throw InvalidSpan();
}

size_t Span::shortestSpan()
{
	size_t span = LONG_LONG_MAX;
	if (this->elementCount > 1)
	{
		long first = LONG_MIN, second = LONG_MIN;
		std::sort(this->list.begin(), this->list.end());
		for (std::vector<int>::iterator it = this->list.begin(); it != this->list.end(); ++it)
		{
			if (first == LONG_MIN)
			{
				first = *it;
				continue;
			}
			second = *it;
			if ((second - first) < static_cast<long>(span))
				span = second - first;
			first = second;
		}
	}
	else
		throw InvalidSpan();
	return (span);
}


const char *Span::SpanException::what()const throw()
{
	return ("Error: Element list full, cannot add new number.");
}

const char *Span::InvalidSpan::what()const throw()
{
	return ("Error: Cannot get span.");
}

