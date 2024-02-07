/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:36:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/07 18:01:58 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(6);
		sp.addNumber(5);
		sp.addNumber(-20);
		sp.addNumber(-15);
		sp.addNumber(-17);
		sp.addNumber(-9);
		sp.addNumber(0);
		std::cout << "Longest span sp: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span sp: " << sp.shortestSpan() << std::endl;

		std::cout << std::endl;
		Span sp2 = Span(10000);
		std::vector<int> vec;
		for (int index = 0; index < 10000; index++)
			vec.push_back(index);
		sp2.addNumber(vec.begin(), vec.end());
		std::cout << "Longest span sp2: " << sp2.longestSpan() << std::endl;
		std::cout << "Shortest span sp2: " << sp2.shortestSpan() << std::endl;

		std::cout << std::endl;
		Span sp3 = Span(1);
		sp3.addNumber(1);
		std::cout << "Longest span sp3: " << sp3.longestSpan() << std::endl;
		//sp3.addNumber(2);

		return (0);
	}
	catch (std::exception &exception)
	{
		std::cout << std::endl << exception.what() << std::endl;
		return (1);
	}
}