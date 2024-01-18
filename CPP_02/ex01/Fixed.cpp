/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:06:23 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 00:21:56 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->integer = roundf(integer * (1 << this->bits));
}

Fixed::Fixed(const float floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->integer = roundf(floater * (1 << this->bits));;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->integer = other.integer;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

float	Fixed::toFloat() const {return (this->integer / static_cast<float>(1 << this->bits));}

int Fixed::toInt() const {return (this->integer / (1 << this->bits));}
