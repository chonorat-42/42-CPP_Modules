/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:34:12 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/22 17:58:30 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(10);
	Fixed d(0);

	std::cout << a << " a" << std::endl;
	std::cout << ++a << " ++a" << std::endl;
	std::cout << a << " a" << std::endl;
	std::cout << a++ << " a++" << std::endl;
	std::cout << a << " a" << std::endl;
	std::cout << std::endl;

	std::cout << c << " c" << std::endl;
	std::cout << --c << " --c" << std::endl;
	std::cout << c-- << " c--" << std::endl;
	std::cout << c << " c" << std::endl;
	std::cout << std::endl;

	std::cout << a << " a" << std::endl;
	std::cout << b << " b" << std::endl;
	std::cout << Fixed::max(a, b) << " max(a, b)" << std::endl;
	std::cout << a + b << " a + b" << std::endl;
	std::cout << a - b << " a - b" << std::endl;
	std::cout << a * b << " a * b" << std::endl;
	std::cout << a / b << " a / b" << std::endl;
	std::cout << a / d << " a  / d" << std::endl;
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
	return 0;
}