/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:28:15 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/25 13:25:15 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaList.hpp"

MateriaList::MateriaList() : _list(NULL) {}

MateriaList::MateriaList(const MateriaList &other) {*this = other;}

MateriaList &MateriaList::operator=(const MateriaList &other)
{
	this->_list = other._list;
	return (*this);
}

MateriaList::~MateriaList()
{
	const List *current = this->_list;

	while (current)
	{
		if (current->materia)
			delete current->materia;
		const List *next = current->next;
		delete current;
		current = next;
	}
}

void MateriaList::addMateria(AMateria *materia)
{

	if (!materia)
		return ;
	List *tmp = this->_list;
	List *newList = new List;
	while (tmp && tmp->next)
		tmp = tmp->next;
	newList->materia = materia;
	newList->prev = tmp;
	newList->next = NULL;
	if (tmp)
		tmp->next = newList;
	else
		this->_list = newList;
}
