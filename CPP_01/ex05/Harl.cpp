/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:51:22 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/08 15:35:53 by chonorat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	map["info"] = &Harl::info;
	map["debug"] = &Harl::debug;
	map["warning"] = &Harl::warning;
	map["error"] = &Harl::error;
}

void	Harl::complain(std::string level)
{
		std::map<std::string, void(Harl::*)()>::iterator it = map.find(level);
		(this->*(it->second))();
}

void	Harl::debug() {std::cout << "debug" << std::endl;}
void	Harl::info() {std::cout << "info" << std::endl;}
void	Harl::warning() {std::cout << "warning" << std::endl;}
void	Harl::error() {std::cout << "error" << std::endl;}
