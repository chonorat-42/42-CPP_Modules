/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:56 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/03 13:31:40 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch (ScalarConverter::ImpossibleConversion& exception)
		{
			std::cout << "Error: " << exception.what() << std::endl;
			return (1);
		}
	}
	return (0);
}