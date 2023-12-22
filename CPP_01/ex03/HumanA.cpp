/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:20:20 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/22 14:33:16 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &newWeapon) : name(name), weapon(newWeapon){}

void	HumanA::attack()const {std::cout << name << " attacks with their " << weapon.getType() << std::endl;}
