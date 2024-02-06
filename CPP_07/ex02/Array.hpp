/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:17:30 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/06 16:33:41 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	public:
		Array();
		explicit Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](size_t index);
		T operator[](size_t index)const;
		~Array();
		size_t size()const;
		class outOfBounds : public std::exception
		{
			public:
				const char* what()const throw();
		};

	private:
		T* _array;
		size_t _size;
};

template<typename T>
Array<T>::Array()
{
	this->_array = new T[0];
	this->_size = 0;
}

template<typename T>
Array<T>::Array(const unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
	for (size_t index = 0; index < n; index++)
		this->_array[index] = T();
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->_size = other._size;
	this->_array = new T[other._size];
	for (size_t index = 0; index < other._size; index++)
		this->_array[index] = other._array[index];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[other._size];
		for (size_t index = 0; index < other._size; index++)
			this->_array[index] = other._array[index];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= this->_size)
		throw outOfBounds();
	return (this->_array[index]);
}

template<typename T>
T Array<T>::operator[](size_t index)const
{
	if (index >= this->_size)
		throw outOfBounds();
	return (this->_array[index]);
}

template<typename T>
size_t Array<T>::size()const
{
	return (this->_size);
}

template<typename T>
const char *Array<T>::outOfBounds::what()const throw()
{
	return ("Index is out of bounds");
}

#endif //ARRAY_HPP
