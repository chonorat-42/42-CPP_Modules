/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:29:38 by chonorat          #+#    #+#             */
/*   Updated: 2023/12/21 18:29:59 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::addIndex(int index) {this->index = index;}

void	Contact::addFirstName(std::string input) {firstName = input;}

void	Contact::addLastName(std::string input) {lastName = input;}

void	Contact::addNickName(std::string input) {nickName = input;}

void	Contact::addPhoneNumber(std::string input) {phoneNumber = input;}

void	Contact::addSecret(std::string input) {secret = input;}

std::string	Contact::getIndex() {return (to_string(index));}

std::string	Contact::getFirstName() {return (firstName);}

std::string	Contact::getLastName() {return (lastName);}

std::string	Contact::getNickName() {return (nickName);}

std::string	Contact::getPhoneNumber() {return (phoneNumber);}

std::string	Contact::getSecret() {return (secret);}
