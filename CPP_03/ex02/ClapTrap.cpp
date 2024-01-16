/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:01:44 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/16 18:41:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {std::cout << "ClapTrap is created" << std::endl;};

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap is created" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->maxHitPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap& other) {*this = other;}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap is destructed" << std::endl;}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints && this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target;
		std::cout << ", causing " << this->attackDamage << " points of damage !" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints)
	{
		this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints && this->energyPoints)
	{
		this->hitPoints += amount;
		if (this->hitPoints > this->maxHitPoints)
			this->hitPoints = this->maxHitPoints;
		this->energyPoints--;
	}
}
