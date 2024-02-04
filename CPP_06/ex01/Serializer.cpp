/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:54:51 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/04 16:15:21 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& other) {(void)other; return *this;}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
	if (ptr)
		return (reinterpret_cast<uintptr_t>(ptr));
	return (0);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
