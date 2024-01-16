/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:37:36 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/16 18:40:26 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap is created" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->maxHitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &other) {*this = other;}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap destructed" << std::endl;}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints && this->energyPoints)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target;
		std::cout << ", causing " << this->attackDamage << " points of damage !" << std::endl;
		this->energyPoints--;
	}
}

void ScavTrap::guardGate() {std::cout << "ScavTrap is in gate keeper mode" << std::endl;}
