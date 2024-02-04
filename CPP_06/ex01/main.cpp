/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:19:21 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/04 16:36:58 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data* storage = new Data();
	uintptr_t cast = Serializer::serialize(storage);
	Data* copy = Serializer::deserialize(cast);

	storage->setValue(42);
	std::cout << "storage value: " << storage->getValue() << std::endl;
	std::cout << "storage adress: " << storage << std::endl;
	std::cout << "copy value: " << copy->getValue() << std::endl;
	std::cout << "copy adress: " << copy << std::endl;
	std::cout << std::endl;
	std::cout << "copy value set to 21" << std::endl;
	copy->setValue(21);
	std::cout << "copy value: " << copy->getValue() << std::endl;
	std::cout << "storage value: " << storage->getValue() << std::endl;
	delete storage;
	return (0);
}