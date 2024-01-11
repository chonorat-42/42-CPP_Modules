/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:00:10 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/11 16:13:37 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() : functionArr()
{
	level[0] = "DEBUG";
	level[1] = "INFO";
	level[2] = "WARNING";
	level[3] = "ERROR";
	functionArr[0] = &Harl::debug;
	functionArr[1] = &Harl::info;
	functionArr[2] = &Harl::warning;
	functionArr[3] = &Harl::error;
}

void	Harl::complain(std::string level)
{
	for (int index = 0; index < 4; index++)
	{
		if (!this->level[index].compare(level))
			(this->*functionArr[index])();
	}
}

void	Harl::debug() {std::cout << "DEBUG" << std::endl;}
void	Harl::info() {std::cout << "INFO" << std::endl;}
void	Harl::warning() {std::cout << "WARNING" << std::endl;}
void	Harl::error() {std::cout << "ERROR" << std::endl;}
