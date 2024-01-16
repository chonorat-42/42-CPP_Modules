/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:45:42 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/16 18:53:05 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap is created" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->maxHitPoints = 100;
}

FragTrap::FragTrap(const FragTrap &other) {*this = other;}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " is asking for high fives" << std::endl;
}

FragTrap::~FragTrap() {std::cout << "FragTrap destructed" << std::endl;}