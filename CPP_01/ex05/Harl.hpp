/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:51:15 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/08 14:53:47 by chonorat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <map>

class Harl
{
	public:
		Harl();
		void complain(std::string level);

	private:
		std::map<std::string, void(Harl::*)()> map;
		void 	debug();
		void	info();
		void	warning();
		void	error();
};

#endif
