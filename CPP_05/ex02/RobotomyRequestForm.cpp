/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:07:46 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:08 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45),
	_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::randomizeResult()const
{
	srand(std::time(0));
	std::cout << "BRRRRrrrrrrrrrrrr..." << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Attempt to robotomize " << this->_target << " failed." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)const
{
	checkPrerequisites(executor);
	this->randomizeResult();
}
