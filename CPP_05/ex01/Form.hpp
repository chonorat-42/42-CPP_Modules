/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:08 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/26 19:35:27 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		std::string getName()const;
		int getGradeToSign()const;
		int getGradeToExecute()const;
		bool getIsSigned()const;
		void beSigned(Bureaucrat &bureaucrat);

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what()const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what()const throw();
	};
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

};

std::ostream& operator<<(std::ostream &os, const Form& other);
