/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:08 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 15:51:56 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

Form &Form::operator=(const Form &other)
{
	(void)other;
	return (*this);
}

Form::~Form() {}

std::string Form::getName()const {return (this->_name);}

int Form::getGradeToSign()const {return (this->_gradeToSign);}

int Form::getGradeToExecute()const {return (this->_gradeToExecute);}

bool Form::getIsSigned()const {return (this->_isSigned);}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (!this->getIsSigned())
	{
		try
		{
			if (bureaucrat.getGrade() <= this->getGradeToSign())
			{
				this->_isSigned = true;
				std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
			}
			else
				throw GradeTooLowException();
		}
		catch (GradeTooLowException& exception)
		{
			std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because "
				<< exception.what() << std::endl;
		}
	}
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	os << other.getName() << " form, grade to sign: " << other.getGradeToSign() << ", grade to execute: ";
	os << other.getGradeToExecute() << ", is signed: " << other.getIsSigned();
	return (os);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}
