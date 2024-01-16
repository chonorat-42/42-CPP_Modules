/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:34:12 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/16 15:51:21 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	if (b > a)
		std::cout << "b is greater than a" << std::endl;
	if (a < b)
		std::cout << "a is less than b" << std::endl;
	if (b >= a)
		std::cout << "b is greater or equal to a" << std::endl;
	if (a <= b)
		std::cout << "a is less or equal to b" << std::endl;
	if (Fixed(10) == Fixed(10))
		std::cout << "is equal" << std::endl;
	if (b != a)
		std::cout << "b is not equal to a" << std::endl;
}