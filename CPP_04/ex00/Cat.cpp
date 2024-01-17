/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:56:30 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 15:05:20 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other) {*this = other;}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	return (*this);
}

Cat::~Cat() {std::cout << "Cat destructed" << std::endl;}

void Cat::makeSound()const {std::cout << "Miaou" << std::endl;}
