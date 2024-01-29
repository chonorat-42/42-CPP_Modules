/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:55 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/29 17:11:50 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137),
	_target("default_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137),
	_target(target + "_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::_writeTree()const
{
	std::ofstream out(this->_target.c_str(), std::ofstream::ate | std::ofstream::app | std::ofstream::out);

	if (out.is_open())
	{
		out << TREE;
		out.close();
	}
	else
		std::cout << "Cannot open " << this->_target << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor)const
{
	try
	{
		if (!this->getIsSigned())
			throw FormNotSigned();
		if (executor.getGrade() >= this->getGradeToExecute())
			throw Bureaucrat::GradeTooLowException();
		this->_writeTree();
	}
	catch (std::exception& exception)
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because "
			<< exception.what() << std::endl;
	}
}
