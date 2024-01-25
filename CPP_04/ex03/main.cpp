/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:56:49 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/25 13:23:44 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaList.hpp"
#include "MateriaSource.hpp"

int main()
{
	MateriaList *list = new MateriaList();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria *ice = src->createMateria("ice");
	me->equip(ice);
	AMateria *cure = src->createMateria("cure");
	me->equip(cure);
	AMateria *fire = src->createMateria("fire");
	me->equip(fire);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(4, *bob);
	me->use(-1, *bob);

	list->addMateria(ice);
	me->unequip(0);
	list->addMateria(cure);
	me->unequip(1);
	list->addMateria(fire);
	me->unequip(2);

	delete bob;
	delete me;
	delete src;
	delete list;

	return 0;
}