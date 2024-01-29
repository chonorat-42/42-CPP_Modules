/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:40:09 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/29 18:49:35 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define TREE "       ###\n      #o###\n    #####o###\n   #o##|#/###\n    ###|/#o#\n     # }|{  #\n       }|{\n"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void execute(const Bureaucrat& executor)const;

	private:
		std::string _target;
		void _writeTree()const;
};
