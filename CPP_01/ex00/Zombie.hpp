/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:49:04 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 16:35:54 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
	public:
		explicit Zombie(const std::string& name);
		~Zombie();
		void	announce();

	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif