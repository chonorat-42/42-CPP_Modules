/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/29 18:47:37 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	RobotomyRequestForm *form = new RobotomyRequestForm("A1");
	Bureaucrat *bureaucrat = new Bureaucrat("test", 130);

	bureaucrat->signForm(*form);
	form->execute(*bureaucrat);
	delete form;
	delete bureaucrat;
	return (0);
}