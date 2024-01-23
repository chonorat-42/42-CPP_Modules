/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:36 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/23 17:30:53 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {*this = other;}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()const {return (this->_name);}

int Bureaucrat::getGrade()const {return (this->_grade);}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade > 1)
			this->_grade--;
		else
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &exception)
	{
		exception.what();
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade < 150)
			this->_grade++;
		else
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &exception)
	{
		exception.what();
	}
}


const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Error: 'Bureaucrat grade too high'");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Error: 'Bureaucrat grade too low'");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << '.' << std::endl;
	return (out);
}
