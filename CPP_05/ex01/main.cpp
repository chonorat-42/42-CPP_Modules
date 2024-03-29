/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 16:04:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);
	Form *form = NULL;
	try
	{
		form = new Form("A1", 150, 50);
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
		Form form2("A2", 151, 50);
	}
	catch (const std::exception &exception)
	{
		std::cout << "A Form " <<  exception.what() << std::endl;
		delete form;
		delete bureaucrat;
		return (1);
	}
	delete form;
	delete bureaucrat;
	return (0);
}