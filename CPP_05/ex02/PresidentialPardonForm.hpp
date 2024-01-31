/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:20:36 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/31 14:58:23 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void execute(const Bureaucrat &executor)const;

	private:
		std::string _target;
		PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

#endif