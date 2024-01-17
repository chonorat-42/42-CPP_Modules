/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:26:45 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 16:38:20 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) {*this = other;}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
	delete this->brain;
}

void Dog::makeSound()const {std::cout << "Wouf" << std::endl;}

void Dog::setBrain()
{
	for (int index = 0; index < 100; index++)
		this->brain->setIdea(index, "Eat");
}
