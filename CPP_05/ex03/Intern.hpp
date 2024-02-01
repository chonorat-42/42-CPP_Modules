/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:03:18 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 13:10:39 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		AForm* makeForm(std::string name, std::string target);

	private:
		std::string _formIndex[3];
		AForm* (Intern::*_makeForm[3])(std::string& target);
		AForm* makeShrubbery(std::string& target);
		AForm* makeRobotomy(std::string& target);
		AForm* makePresidential(std::string& target);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
};

#endif //INTERN_HPP
