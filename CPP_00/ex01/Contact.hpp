/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:34:36 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/20 16:29:25 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Contact
{
	public:
		void addIndex(int index) {this->index = index;};
		void addFirstName(std::string input) {firstName = input;};
		void addLastName(std::string input) {lastName = input;};
		void addNickName(std::string input) {nickName = input;};
		void addPhoneNumber(std::string input) {phoneNumber = input;};
		void addSecret(std::string input) {secret = input;};
		std::string	getIndex() {return (std::to_string(index));};
		std::string getFirstName() {return (firstName);};
		std::string getLastName() {return (lastName);};
		std::string getNickName() {return (nickName);};
		std::string getPhoneNumber() {return (phoneNumber);};
		std::string getSecret() {return (secret);};

	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;
};
