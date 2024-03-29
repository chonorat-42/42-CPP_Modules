/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:40:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/01 15:33:00 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

#define TREE "       ###\n      #o###\n    #####o###\n   #o##|#/###\n    ###|/#o#\n     # }|{  #\n       }|{\n"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		void execute(const Bureaucrat& executor)const;

	private:
		std::string _target;
		void _writeTree()const;
		ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
};

#endif