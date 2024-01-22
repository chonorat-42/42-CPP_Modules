/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:39:51 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/22 18:24:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		explicit Fixed(const int integer);
		explicit Fixed(const float floater);
		Fixed(const Fixed &other);
		Fixed	&operator =(const Fixed &other);
		Fixed	&operator ++();
		Fixed	operator ++(int);
		Fixed	&operator --();
		Fixed	operator --(int);
		Fixed	operator +(const Fixed &other)const;
		Fixed	operator -(const Fixed &other)const;
		Fixed	operator *(const Fixed &other)const;
		Fixed	operator /(const Fixed &other)const;
		bool	operator >(const Fixed &other)const;
		bool	operator <(const Fixed &other)const;
		bool	operator >=(const Fixed &other)const;
		bool	operator <=(const Fixed &other)const;
		bool	operator ==(const Fixed &other)const;
		bool	operator !=(const Fixed &other)const;
		static Fixed	&min(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static Fixed	&max(Fixed &first, Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);
		float	toFloat() const;
		int		toInt() const;
		~Fixed();

	private:
		int integer;
		static const int bits = 8;
};

std::ostream	&operator <<(std::ostream &os, const Fixed &other);

#endif //FIXED_HPP
