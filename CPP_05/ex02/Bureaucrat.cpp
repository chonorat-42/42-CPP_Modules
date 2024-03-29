/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:36 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/31 14:17:18 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
		if (grade < 1)
			throw GradeTooHighException();
		this->_grade = grade;
	}
	catch (GradeTooLowException &exception)
	{
		std::cout << "Grade set to 150 because " << exception.what() << std::endl;
		this->_grade = 150;
	}
	catch (GradeTooHighException &exception)
	{
		std::cout << "Grade set to 1 because " << exception.what() << std::endl;
		this->_grade = 1;
	}
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
		std::cout << exception.what() << std::endl;
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
		std::cout << exception.what() << std::endl;
	}
}


const char *Bureaucrat::GradeTooHighException::what()const throw()
{
	return ("bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what()const throw()
{
	return ("bureaucrat grade is too low");
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& exception)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because "
			<< exception.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << '.';
	return (os);
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << this->getName() << " cannot execute " << form.getName() << " because "
			<< exception.what() << std::endl;
	}
}
