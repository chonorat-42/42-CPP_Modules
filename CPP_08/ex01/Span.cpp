/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:35:38 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/07 00:14:24 by chonorat         ###   ########.fr       */
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

void Span::addNumber(int integer)
{
	if (this->elementCount < this->listSize)
	{
		this->list.push_back(integer);
		this->elementCount++;
	}
	else
		throw SpanException();
}



const char *Span::SpanException::what() const throw()
{
	return ("Error: Element list full, cannot add new number.");
}
