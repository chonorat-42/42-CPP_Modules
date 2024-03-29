/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:42 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 16:00:56 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
	public:
		explicit Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string getName()const;
		int getGrade()const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);
		class GradeTooHighException : public std::exception
		{
			public:
			const char *what()const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what()const throw();
		};

	private:
		const std::string _name;
		int _grade;
		Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other);
