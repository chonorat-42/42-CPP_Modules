/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:10:43 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/22 01:06:30 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde = new(std::nothrow) Zombie[n];

	if (!horde)
		return (NULL);
	for (int index = 0; index < n; index++)
		horde[index].nameZombie(name);
	return (horde);
}
