/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:00:20 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/22 13:51:47 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		const std::string	&getType();
		void	setType(std::string type);

	private:
		std::string	type;
};

#endif
