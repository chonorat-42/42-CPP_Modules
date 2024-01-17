/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:36:49 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 15:05:08 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {std::cout << "Animal created" << std::endl;}

Animal::Animal(const Animal &other) {*this = other;}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	return (*this);
}

Animal::~Animal() {std::cout << "Animal destructed" << std::endl;}

void Animal::makeSound()const {std::cout << "Animal sound" << std::endl;}

std::string Animal::getType()const {return (this->type);}
