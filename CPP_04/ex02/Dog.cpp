/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:26:45 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:40:28 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	this->brain = new Brain();
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	*this->brain = *other.brain;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
	delete this->brain;
}

void Dog::makeSound()const {std::cout << "Wouf" << std::endl;}

void Dog::setBrain(const int location, const std::string& idea)const {this->brain->setIdea(location, idea);}

std::string Dog::getBrain(const int location)const {return this->brain->getIdea(location);}