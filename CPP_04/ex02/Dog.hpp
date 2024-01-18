/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:27:40 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:40:47 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AbstractAnimal.hpp"

class Dog : public AbstractAnimal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound()const;
		void setBrain(int location, const std::string& idea)const;
		std::string getBrain(int location)const;

	private:
		Brain *brain;
};

#endif //DOG_HPP
