/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:57:29 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 16:51:12 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &other) {this->_type = other._type;}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {return (this->_type);}

void AMateria::use(ICharacter& target)
{
	(void)target;
}