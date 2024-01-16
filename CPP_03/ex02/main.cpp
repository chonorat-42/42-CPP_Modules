/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:37:28 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/16 18:52:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Tupac");
	ScavTrap scav("Biggie");
	FragTrap frag("Snoop");

	clap.attack("Biggie");
	scav.attack("Tupac");
	frag.attack("Tupac");
	scav.guardGate();
	clap.beRepaired(5);
	frag.highFivesGuys();
	return (0);
}