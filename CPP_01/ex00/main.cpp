/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:47:44 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 16:43:48 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*biggie;

	biggie = newZombie("Biggie");
	biggie->announce();
	randomChump("Tupac");
	delete biggie;
	return (0);
}