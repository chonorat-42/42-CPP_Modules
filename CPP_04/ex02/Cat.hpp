/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:56:44 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/18 14:20:07 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AbstractAnimal.hpp"

class Cat : public AbstractAnimal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound()const;
		void setBrain(int location, const std::string& idea)const;
		std::string getBrain(int location)const;

	private:
		Brain *brain;
};

#endif //CAT_HPP
