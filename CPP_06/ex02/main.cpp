/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:44:00 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/04 17:40:03 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	try
	{
		std::cout << "Identify by pointer:" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}