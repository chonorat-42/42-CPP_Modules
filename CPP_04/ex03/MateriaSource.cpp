/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:39:20 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/19 18:05:17 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int index = 0; index < 4; index++)
		this->_stock[index] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int index = 0; index < 4; index++)
	{
		this->_stock[index] = NULL;
		if (other._stock[index])
			this->_stock[index] = other._stock[index]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int index = 0; index < 4; index++)
	{
		if (this->_stock[index])
		{
			delete this->_stock[index];
			this->_stock[index] = NULL;
		}
		if (other._stock[index])
			this->_stock[index] = other._stock[index]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int index = 0; index < 4; index++)
	{
		if (this->_stock[index] != NULL)
			delete this->_stock[index];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int index = 0; index < 4; index++)
	{
		if (!this->_stock[index])
		{
			this->_stock[index] = materia;
			return ;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int index = 0; index < 4; index++)
	{
		if (this->_stock[index] && this->_stock[index]->getType().compare(type) == 0)
			return (this->_stock[index]->clone());
	}
	return (NULL);
}
