/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:07:46 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/29 18:55:24 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45),
	_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)const
{
	try
	{
		if (!this->getIsSigned())
			throw FormNotSigned();
		if (executor.getGrade() > this->getGradeToExecute())
			throw Bureaucrat::GradeTooLowException();
		std::cout << _randomizeResult() << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because "
			<< exception.what() << std::endl;
	}
}

int RobotomyRequestForm::_randomizeResult()const
{
	return (rand() % 2);
}
