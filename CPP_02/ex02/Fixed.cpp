/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:34:42 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/22 18:30:50 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {this->integer = 0;}

Fixed::Fixed(const int integer)
{
	this->integer = roundf(static_cast<float>(integer) * (1 << this->bits));
}

Fixed::Fixed(const float floater)
{
	this->integer = roundf(floater * static_cast<float>(1 << this->bits));;
}

Fixed::Fixed(const Fixed& other) {*this = other;}

Fixed::~Fixed() {}

float	Fixed::toFloat() const {return (this->integer / static_cast<float>(1 << this->bits));}

int Fixed::toInt() const {return (this->integer / (1 << this->bits));}

Fixed&	Fixed::operator =(const Fixed& other)
{
	if (this != &other)
		this->integer = other.integer;
	return (*this);
}

std::ostream& operator <<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

Fixed& Fixed::operator ++()
{
	this->integer++;
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	const Fixed	temp(*this);

	operator++();
	return (temp);
}

Fixed& Fixed::operator --()
{
	this->integer--;
	return (*this);
}

Fixed Fixed::operator --(int)
{
	const Fixed	temp(*this);

	operator--();
	return (temp);
}

Fixed	Fixed::operator +(const Fixed &other)const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator -(const Fixed &other)const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator *(const Fixed &other)const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed	Fixed::operator /(const Fixed &other)const
{
	if (other.toFloat() == 0 || this->toFloat() == 0)
	{
		std::cerr << "Division by 0 is not possible" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	return ((first.integer < second.integer) ? first : second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	return ((first.integer < second.integer) ? first : second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	return ((first.integer > second.integer) ? first : second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	return ((first.integer > second.integer) ? first : second);
}

bool	Fixed::operator >(const Fixed &other)const
{
	return ((this->integer > other.integer));
}

bool	Fixed::operator <(const Fixed &other)const
{
	return ((this->integer < other.integer));
}

bool	Fixed::operator >=(const Fixed &other)const
{
	return ((this->integer >= other.integer));
}

bool	Fixed::operator <=(const Fixed &other)const
{
	return ((this->integer <= other.integer));
}

bool	Fixed::operator ==(const Fixed &other)const
{
	return ((this->integer == other.integer));
}

bool	Fixed::operator !=(const Fixed &other)const
{
	return ((this->integer != other.integer));
}
