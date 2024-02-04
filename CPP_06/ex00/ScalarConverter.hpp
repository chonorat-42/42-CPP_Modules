/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:10:16 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/03 23:44:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cmath>
# include <climits>
# include <cstring>
# include "TypeData.hpp"

class ScalarConverter
{
	public:
		static void convert(std::string literal);
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
