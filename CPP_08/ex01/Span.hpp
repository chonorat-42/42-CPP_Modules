/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:35:49 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/07 17:39:24 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <limits>
# include <iostream>
# include <limits.h>
# include <algorithm>

class Span
{
	public:
		explicit Span(unsigned int max);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int integer);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		size_t shortestSpan();
		size_t longestSpan();
		class SpanException : public std::exception
		{
			public:
				virtual const char* what()const throw();
		};
		class InvalidSpan : public std::exception
		{
			public:
				virtual const char* what()const throw();
		};

	private:
		size_t elementCount;
		size_t listSize;
		std::vector<int> list;
		int getMaxNumber()const;
		int getMinNumber()const;
		Span();
};

#endif //SPAN_HPP
