/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:44:00 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/16 18:48:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		explicit FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		FragTrap &operator =(const FragTrap &other);
		~FragTrap();
		void highFivesGuys();
};

#endif //FRAGTRAP_HPP
