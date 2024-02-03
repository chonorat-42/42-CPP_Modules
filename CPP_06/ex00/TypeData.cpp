/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:27:19 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/03 15:59:18 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeData.hpp"

TypeData::TypeData() {}

TypeData::TypeData(const char character, const int integer, const float floating, const double doublePrecision) :
	character(character), integer(integer), floating(floating), doublePrecision(doublePrecision) {}

TypeData::~TypeData() {}

TypeData::TypeData(const TypeData& other) {*this = other;}

TypeData& TypeData::operator=(const TypeData& other)
{
	if (this != &other)
	{
		this->character = other.character;
		this->integer = other.integer;
		this->floating = other.floating;
		this->doublePrecision = other.doublePrecision;
	}
	return (*this);
}

char TypeData::getCharacter() const {return (this->character);}

int TypeData::getInteger() const {return (this->integer);}

float TypeData::getFloating() const {return (this->floating);}

double TypeData::getDoublePrecision() const {return (this->doublePrecision);}
