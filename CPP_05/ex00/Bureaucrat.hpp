/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:42 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/23 17:06:45 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

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

	private:
		const std::string _name;
		int _grade;

	class GradeTooHighException : std::exception
	{
		public:
		const char *what()const noexcept;
	};

	class GradeTooLowException : std::exception
	{
		public:
		const char *what()const noexcept;
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other);

#endif //BUREAUCRAT_HPP
