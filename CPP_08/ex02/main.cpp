/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:04:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/08 15:43:52 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int>	mstack;

	std::cout << "mstack.push(5)" << std::endl;
	mstack.push(5);
	std::cout << "mstack.push(17)" << std::endl;
	mstack.push(17);
	std::cout << std::endl;

	std::cout << "mstack.top(): " << mstack.top() << std::endl;

	std::cout << "mstack.pop()" << std::endl << std::endl;
	mstack.pop();

	std::cout << "mstack.size(): " << mstack.size() << std::endl << std::endl;

	std::cout << "mstack.push(3)" << std::endl;
	mstack.push(3);
	std::cout << "mstack.push(5)" << std::endl;
	mstack.push(5);
	std::cout << "mstack.push(737)" << std::endl;
	mstack.push(737);
	std::cout << "mstack.push(0)" << std::endl;
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << "*it = " << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::cout << "std::stack<int> s(mstack)" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "s.size(): " << s.size() << std::endl;
	std::cout << std::endl;
	std::cout << "s.push(42)" << std::endl;
	s.push(42);
	std::cout << "s.size(): " << s.size() << std::endl;
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "s.top(): " << s.top() << std::endl;
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << "it = mstack.begin()" << std::endl;
	it = mstack.begin();
	while (it != ite)
	{
		std::cout << "*it = " << *it << std::endl;
		++it;
	}
	return (0);
}