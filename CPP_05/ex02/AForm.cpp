/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:08 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/26 18:22:52 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName()const {return (this->_name);}

int AForm::getGradeToSign()const {return (this->_gradeToSign);}

int AForm::getGradeToExecute()const {return (this->_gradeToExecute);}

bool AForm::getIsSigned()const {return (this->_isSigned);}

void AForm::beSigned(Bureaucrat &bureaucrat)
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

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	os << other.getName() << " form, grade to sign: " << other.getGradeToSign() << ", grade to execute: ";
	os << other.getGradeToExecute() << ", is signed: " << other.getIsSigned();
	return (os);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("form is not signed");
}
