/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:05:53 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/12 18:44:30 by chonorat         ###   ########.fr       */
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
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();
		float	toFloat()const;
		int		toInt()const;

	private:
		int		integer;
		static const int bits = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& other);

#endif //FIXED_HPP
