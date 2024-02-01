/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:08 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 15:30:30 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		std::string getName()const;
		int getGradeToSign()const;
		int getGradeToExecute()const;
		bool getIsSigned()const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat& executor)const = 0;

	protected:
		class FormNotSigned : public std::exception
		{
			public:
				const char *what()const throw();
		};
		class FormAlreadySigned : public std::exception
		{
			public:
				const char *what()const throw();
		};
		void checkPrerequisites(const Bureaucrat& executor)const;
		AForm &operator=(const AForm &other);
		AForm(const AForm &other);

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

};

std::ostream& operator<<(std::ostream &os, const AForm& other);
