/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:04:39 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/08 15:40:10 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	this->c = other.c;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif //MUTANTSTACK_HPP
