/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:23 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:29:23 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {std::cout << "Brain created" << std::endl;}

Brain::Brain(const Brain &other)
{
	for (int index = 0; index < 100; index++)
		this->ideas[index] = other.ideas[index];
}

Brain &Brain::operator=(const Brain &other)
{
	for (int index = 0; index < 100; index++)
			this->setIdea(index, other.ideas[index]);
	return (*this);
}

Brain::~Brain() {std::cout << "Brain destructed" << std::endl;}

void Brain::setIdea(const int location, const std::string& idea)
{
	if (location < 0 || location > 99)
		return ;
	this->ideas[location] = idea;
}

std::string Brain::getIdea(const int location)
{
	if (location < 0 || location > 99)
		return ("Invalid location");
	return (this->ideas[location]);
}