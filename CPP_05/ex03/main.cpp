/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 13:38:10 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* A1 = intern.makeForm("shrubbery creation", "test");
	AForm* A2 = intern.makeForm("robotomy request", "test");
	AForm* A3 = intern.makeForm("presidential pardon", "test");
	AForm* A4 = intern.makeForm("test", "test");

	if (A1)
		std::cout << *A1 << std::endl;
	if (A2)
		std::cout << *A2 << std::endl;
	if (A3)
		std::cout << *A3 << std::endl;
	if (A4)
		std::cout << *A4 << std::endl;

	if (A1)
		delete A1;
	if (A2)
		delete A2;
	if (A3)
		delete A3;
	if (A4)
		delete A4;
	return (0);
}