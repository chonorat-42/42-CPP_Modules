/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/26 15:18:17 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);
	Form *form = new Form("A1", 50, 50);

	std::cout << *bureaucrat << std::endl;
	std::cout << *form << std::endl;
	std::cout << std::endl;
	bureaucrat->signForm(*form);
	std::cout << *form << std::endl;
	std::cout << std::endl;
	for (int index = 0; index < 100; index++)
		bureaucrat->incrementGrade();
	std::cout << *bureaucrat << std::endl;
	bureaucrat->signForm(*form);
	std::cout << *form << std::endl;
	return (0);
}