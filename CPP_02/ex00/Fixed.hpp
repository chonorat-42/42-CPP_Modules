/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:46:38 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:51 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();
		int		getRawBits()const;
		void	setRawBits(int const raw);

	private:
		int	integer;
		const static int	bits = 8;
};

#endif //FIXED_HPP
