/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:08:19 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 13:36:16 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	this->_formIndex[0] = "shrubbery creation";
	this->_formIndex[1] = "robotomy request";
	this->_formIndex[2] = "presidential pardon";
	this->_makeForm[0] = &Intern::makeShrubbery;
	this->_makeForm[1] = &Intern::makeRobotomy;
	this->_makeForm[2] = &Intern::makePresidential;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::Intern(const Intern &other) {*this = other;}

Intern::~Intern() {}


AForm* Intern::makeShrubbery(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	for (int index = 0; index < 3; index++)
	{
		if (!this->_formIndex[index].compare(name))
			return (this->*_makeForm[index])(target);
	}
	std::cout << "No Form named " << name << " found." << std::endl;
	return (NULL);
}
