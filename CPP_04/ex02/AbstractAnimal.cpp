/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:13:47 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:13:47 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal() {std::cout << "Animal created" << std::endl;}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &other) {*this = other;}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &other)
{
	this->type = other.type;
	return (*this);
}

AbstractAnimal::~AbstractAnimal() {std::cout << "Animal destructed" << std::endl;}

std::string AbstractAnimal::getType()const {return (this->type);}
