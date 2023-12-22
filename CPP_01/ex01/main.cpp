/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:09:36 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/22 01:21:00 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;

	horde = zombieHorde(5, "Zomblard");
	if (!horde)
		return (1);
	for (int index = 0; index < 5; index++)
		horde[index].announce();
	delete[] horde;
	return (0);
}
