/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:20:37 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/25 13:16:00 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

struct List
{
	AMateria *materia;
	List *prev;
	List *next;
};

class MateriaList
{
	public:
		MateriaList();
		MateriaList(const MateriaList &other);
		MateriaList &operator=(const MateriaList &other);
		~MateriaList();
		void addMateria(AMateria *materia);

	private:
		List *_list;
};
