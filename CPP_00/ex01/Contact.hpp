/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:34:36 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 18:30:42 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

std::string	to_string(int number);

class	Contact
{
	public:
		void addIndex(int index);
		void addFirstName(std::string input);
		void addLastName(std::string input);
		void addNickName(std::string input);
		void addPhoneNumber(std::string input);
		void addSecret(std::string input);
		std::string	getIndex();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getSecret();

	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;
};

#endif
