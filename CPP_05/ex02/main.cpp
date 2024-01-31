/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/31 14:57:47 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	RobotomyRequestForm *robotomy = new RobotomyRequestForm("A1");
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("A2");
	PresidentialPardonForm *presidential = new PresidentialPardonForm("A3");
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", -1);
	Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat2", 151);

	bureaucrat2->signForm(*robotomy);
	bureaucrat2->signForm(*shrubbery);
	bureaucrat2->signForm(*presidential);
	std::cout << std::endl;

	bureaucrat->executeForm(*robotomy);
	bureaucrat->executeForm(*shrubbery);
	bureaucrat->executeForm(*presidential);
	std::cout << std::endl;

	bureaucrat->signForm(*robotomy);
	bureaucrat->signForm(*robotomy);
	bureaucrat->executeForm(*robotomy);
	std::cout << std::endl;
	bureaucrat->signForm(*shrubbery);
	bureaucrat->executeForm(*shrubbery);
	std::cout << std::endl;
	bureaucrat->signForm(*presidential);
	bureaucrat->executeForm(*presidential);

	delete robotomy;
	delete shrubbery;
	delete presidential;
	delete bureaucrat;
	delete bureaucrat2;
	return (0);
}