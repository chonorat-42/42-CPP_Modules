/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:57:13 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/19 18:07:48 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name)
{
	this->_name = name;
	for (int index = 0; index < 4; index++)
		this->_inventory[index] = NULL;
}

Character::Character(const Character &other)
{
	this->_name = other._name;
	for (int index = 0; index < 4; index++)
	{
		this->_inventory[index] = NULL;
		if (other._inventory[index])
			this->_inventory[index] = other._inventory[index]->clone();
	}
}

Character &Character::operator=(const Character& other)
{
	this->_name = other._name;
	for (int index = 0; index < 4; index++)
	{
		if (this->_inventory[index])
		{
			delete this->_inventory[index];
			this->_inventory[index] = NULL;
		}
		if (other._inventory[index])
			this->_inventory[index] = other._inventory[index]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int index = 0; index < 4; index++)
	{
		if (this->_inventory[index] != NULL)
			delete this->_inventory[index];
	}
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	for (int index = 0; index < 4; index++)
	{
		if (!this->_inventory[index])
		{
			this->_inventory[index] = m;
			return;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
	else
		std::cout << "No Materia to unequip" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "No Materia found" << std::endl;
}
