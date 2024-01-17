/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:22:40 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 15:37:14 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {*this = other;}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructed" << std::endl;}

void WrongAnimal::makeSound()const {std::cout << "WrongAnimal sound" << std::endl;}

std::string WrongAnimal::getType()const {return (this->type);}
