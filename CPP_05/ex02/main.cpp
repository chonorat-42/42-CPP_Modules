/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/26 18:03:10 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm *form = new ShrubberyCreationForm("A1");
	Bureaucrat *bureaucrat = new Bureaucrat("test", 130);

	bureaucrat->signForm(*form);
	form->execute(*bureaucrat);
	delete form;
	delete bureaucrat;
	return (0);
}