/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:58:43 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/12 15:55:20 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <climits>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void sortInVector(char **list);

	private:
		std::vector<int> _vector;
		void storeInVector(char **list);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		class InvalidInteger : public std::exception
		{
			public:
				InvalidInteger(std::string arg);
				~InvalidInteger() throw();
				const char *what()const throw();
			private:
				std::string _message;
		};
		class ListEmpty : public std::exception
		{
			public:
				const char *what()const throw();
		};
};

#endif //PMERGEME_HPP
