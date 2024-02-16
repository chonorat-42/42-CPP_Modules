/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:58:20 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/12 15:50:38 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		try
		{
			PmergeMe sort;
			sort.sortInVector(argv);
			sort.sortInDeque(argv);
			sort.printResult();
		}
		catch (std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Usage: ./PmergeMe [positive integer list]" << std::endl;
		return (1);
	}
	return (0);
}
