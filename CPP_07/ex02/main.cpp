/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:16:56 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/06 16:36:13 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		Array<int> a(5);
		std::cout << "Size: " << a.size() << std::endl;
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		a[3] = 4;
		a[4] = 5;
		a[5] = 6;
		return (0);
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return (1);
	}
}
