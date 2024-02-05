/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:17:30 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/05 18:32:12 by chonorat         ###   ########.fr       */
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
		~Array();
		class outOfBounds : std::exception
		{
			public:
				const char* what()const throw();
		};

	private:
		T* _array;
};

template<typename T>
Array<T>::Array()
{
	this->_array = new T[0];
}

template<typename T>
Array<T>::Array(const unsigned int n)
{
	this->_array = new T[n];
	for (size_t index = 0; index < n; index++)
		this->_array[index] = T();
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->_array = new T[other._array];
	for (size_t index = 0; index < other._array; index++)
		this->_array[index] = other._array[index];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_array = new T[other._array];
		for (size_t index = 0; index < other._array; index++)
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
	try
	{
		if (index > this->_array)
			throw outOfBounds();
		return (this->_array[index]);
	}
	catch (outOfBounds &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

template<typename T>
const char *Array<T>::outOfBounds::what()const throw()
{
	return ("Index is out of bounds");
}

#endif //ARRAY_HPP
