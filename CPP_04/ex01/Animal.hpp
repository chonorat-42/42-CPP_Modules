/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:36:58 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 16:01:12 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void	makeSound()const;
		std::string		getType()const;

	protected:
		std::string type;
};

#endif //ANIMAL_HPP
