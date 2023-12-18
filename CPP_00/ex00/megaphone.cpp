/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:17:37 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/18 14:45:04 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int index = 1; index < argc; index++)
		{
			for (int index_j = 0; argv[index][index_j]; index_j++)
				std::cout << (char)std::toupper(argv[index][index_j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (EXIT_SUCCESS);
}
