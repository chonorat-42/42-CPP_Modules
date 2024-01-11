/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:28:45 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/22 13:52:35 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {this->type = type;}

void	Weapon::setType(std::string type) {this->type = type;}

const std::string	&Weapon::getType()
{
	std::string	&type = this->type;
	return (type);
}
