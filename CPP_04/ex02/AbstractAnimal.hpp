/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:13:54 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:13:54 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AbstractAnimal
{
	public:
		AbstractAnimal();
		AbstractAnimal(const AbstractAnimal &other);
		AbstractAnimal &operator=(const AbstractAnimal &other);
		virtual ~AbstractAnimal();
		virtual void	makeSound()const = 0;
		std::string		getType()const;

	protected:
		std::string type;
};

#endif //ANIMAL_HPP
