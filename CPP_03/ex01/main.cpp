/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:37:28 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/24 01:29:19 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Tupac");
	ScavTrap scav("Biggie");

	clap.getInfo();
	clap.attack("Biggie");
	scav.getInfo();
	scav.attack("Tupac");
	clap.takeDamage(20);
	clap.getInfo();
	scav.guardGate();
	clap.beRepaired(5);
	clap.getInfo();
	return (0);
}