/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:39:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:37:33 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	AbstractAnimal *spa[4];

	//Test AbstractAnimal
	//AbstractAnimal test;

	spa[0] = new Dog();
	spa[1] = new Dog();
	spa[2] = new Cat();
	spa[3] = new Cat();

	Cat *a = new Cat();
	a->setBrain(1, "sleep");
	std::cout << "a->setBrain(1, \"sleep\")" << std::endl << std::endl;
	Cat *b = new Cat(*a);
	std::cout << "b created by copy of a" << std::endl << std::endl;
	delete a;
	std::cout << "a deleted" << std::endl << std::endl;
	std::cout << b->getBrain(1) << std::endl;
	delete b;
	delete spa[0];
	delete spa[1];
	delete spa[2];
	delete spa[3];
	return (0);
}