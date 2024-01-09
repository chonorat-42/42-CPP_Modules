/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:17:37 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 16:43:55 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(const int argc, const char *argv[])
{
	std::string	str;

	if (argc > 1)
	{
		for (int index = 1; index < argc; index++)
		{
			str = argv[index];
			for (unsigned long index_j = 0; index_j < str.length(); index_j++)
				std::cout << static_cast<char>(std::toupper(str[index_j]));
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
