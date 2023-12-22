/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:47:44 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/22 00:47:05 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*biggie;

	biggie = newZombie("Biggie");
	if (!biggie)
		return (1);
	biggie->announce();
	randomChump("Tupac");
	delete biggie;
	return (0);
}