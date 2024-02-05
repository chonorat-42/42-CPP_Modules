/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:35:51 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/05 12:53:41 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 42;
	int b = 21;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "swap a and b" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;
	return (0);
}