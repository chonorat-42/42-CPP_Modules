/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:52:19 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 16:33:12 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name){this->name = name;}

Zombie::~Zombie()
{
	std::cout << Zombie::name << " is being destroyed..." << std::endl;
}

void	Zombie::announce()
{
	if (Zombie::name.length())
		std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
