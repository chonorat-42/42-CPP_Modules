/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:56:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/26 12:24:13 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);

	std::cout << *bureaucrat << std::endl;
	bureaucrat->decrementGrade();
	std::cout << *bureaucrat << std::endl;
	bureaucrat->incrementGrade();
	std::cout << *bureaucrat << std::endl;
	delete bureaucrat;

	Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat2", 1);
	std::cout << std::endl;

	std::cout << *bureaucrat2 << std::endl;
	bureaucrat2->incrementGrade();
	std::cout << *bureaucrat2 << std::endl;
	bureaucrat2->decrementGrade();
	std::cout << *bureaucrat2 << std::endl;
	delete bureaucrat2;

	std::cout << std::endl;
	Bureaucrat *tooHigh = new Bureaucrat("too_high", 151);
	std::cout << *tooHigh << std::endl;
	Bureaucrat *tooLow = new Bureaucrat("too_low", 0);
	std::cout << *tooLow << std::endl;
	delete tooHigh;
	delete tooLow;
	return (0);
}