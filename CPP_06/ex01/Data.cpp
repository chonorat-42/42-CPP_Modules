/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:06:31 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/04 16:20:52 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _value(0) {}

Data::Data(const Data &other) {*this = other;}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Data::~Data() {}

int Data::getValue()const {return (this->_value);}

void Data::setValue(const int value) {this->_value = value;}
