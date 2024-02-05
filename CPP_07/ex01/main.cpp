/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:59:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/05 17:10:16 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

static void print(const int& i) {std::cout << i << " ";}

static void addOne(int& i) {i++;}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	for (int index = 0; index < 5; index++)
	{
		iter(tab, 5, print);
		std::cout << std::endl;
		iter(tab, 5, addOne);
	}
	return 0;
}