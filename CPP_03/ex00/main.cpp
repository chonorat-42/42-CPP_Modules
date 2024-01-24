/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:37:28 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/24 00:55:04 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Tupac");

	clapTrap.getInfo();
	clapTrap.attack("Biggie");
	clapTrap.getInfo();
	clapTrap.takeDamage(2);
	clapTrap.getInfo();
	clapTrap.beRepaired(5);
	clapTrap.getInfo();
	clapTrap.takeDamage(13);
	clapTrap.getInfo();
	clapTrap.attack("Biggie");
	clapTrap.beRepaired(10);
	return (0);
}