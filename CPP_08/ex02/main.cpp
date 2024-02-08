/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:04:27 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/08 15:56:41 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

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
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	std::list<int>	list;
	std::cout << "list.push_back(5)" << std::endl;
	list.push_back(5);
	std::cout << "list.push_back(17)" << std::endl;
	list.push_back(17);
	std::cout << std::endl;

	std::cout << "list.back(): " << list.back() << std::endl;

	std::cout << "list.pop_back()" << std::endl << std::endl;
	list.pop_back();

	std::cout << "list.size(): " << list.size() << std::endl << std::endl;

	std::cout << "list.push_back(3)" << std::endl;
	list.push_back(3);
	std::cout << "list.push_back(5)" << std::endl;
	list.push_back(5);
	std::cout << "list.push_back(737)" << std::endl;
	list.push_back(737);
	std::cout << "list.push_back(0)" << std::endl;
	list.push_back(0);

	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();

	++it2;
	--it2;
	std::cout << std::endl;
	while (it2 != ite2)
	{
		std::cout << "*it = " << *it2 << std::endl;
		++it2;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;

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
