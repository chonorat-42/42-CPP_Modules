/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:44:43 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/17 16:22:46 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
		void setIdea(int location, const std::string& idea);
		std::string getIdea(int location);

	protected:
		std::string ideas[100];
};

#endif //BRAIN_HPP
