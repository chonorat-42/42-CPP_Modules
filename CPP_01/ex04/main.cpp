/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:13:38 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/04 01:13:09 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

int	main(int argc, char *argv[])
{
	FileHandler	data;

	if (argc == 4)
	{
		if (!data.getData(argv))
		{
			std::cerr << "Error: a string is empty" << std::endl;
			return (1);
		}
		if (!data.openFile())
		{
			std::cerr << "Error: failed in attempting to open file" << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	return (0);
}