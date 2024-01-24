/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:01:44 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/24 01:17:10 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap is created" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_maxHitPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap& other) {*this = other;}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap is destructed" << std::endl;}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage !" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
	}
	else
		std::cout << "STOP ! ClapTrap " << this->_name << " is already dead !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of damage !" << std::endl;
		this->_hitPoints += amount;
		if (this->_hitPoints > 10)
			this->_hitPoints = 10;
		this->_energyPoints--;
	}
}

void ClapTrap::getInfo()const
{
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points and ";
	std::cout << this->_energyPoints << " energy points" << std::endl;
}
