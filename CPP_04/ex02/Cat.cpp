/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:56:30 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:38:59 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	this->brain = new Brain();
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	*this->brain = *other.brain;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;
	delete this->brain;
}

void Cat::makeSound()const {std::cout << "Miaou" << std::endl;}

void Cat::setBrain(const int location, const std::string& idea)const {this->brain->setIdea(location, idea);}

std::string Cat::getBrain(const int location)const {return (this->brain->getIdea(location));}