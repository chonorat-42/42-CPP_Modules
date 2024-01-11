/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:07:03 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/11 16:19:58 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	public:
		Harl();
		void complain(std::string level);

	private:
		void		(Harl::*functionArr[4])();
		std::string	level[4];
		void		debug();
		void		info();
		void		warning();
		void		error();
};

#endif
