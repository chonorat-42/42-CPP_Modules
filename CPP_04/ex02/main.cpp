/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:39:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 16:39:17 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	Animal *spa[4];

	spa[0] = new Dog();
	spa[1] = new Dog();
	spa[2] = new Cat();
	spa[3] = new Cat();

	for (int index = 0; index < 2; index++)
	{

	}
}