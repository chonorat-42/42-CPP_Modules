/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:56:44 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 16:43:27 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound()const;
		void setBrain();

	private:
		Brain *brain;
};

#endif //CAT_HPP
