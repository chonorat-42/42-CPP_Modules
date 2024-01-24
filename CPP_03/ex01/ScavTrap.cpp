/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:37:36 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/24 01:27:29 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap is created" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap destructed" << std::endl;}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate() {std::cout << "ScavTrap is in gate keeper mode" << std::endl;}

void ScavTrap::getInfo()const
{
	std::cout << "ScavTrap " << this->_name << " has " << this->_hitPoints << " hit points and ";
	std::cout << this->_energyPoints << " energy points" << std::endl;
}
