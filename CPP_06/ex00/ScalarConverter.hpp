/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:10:16 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/02 17:33:10 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include <cstring>

class ScalarConverter
{
	public:
		static void convert(std::string str);
		class ImpossibleConversion : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

#endif //SCALARCONVERTER_HPP
