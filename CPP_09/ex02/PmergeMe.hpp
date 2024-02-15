/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:58:43 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/15 19:27:33 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <climits>
# include <vector>
# include <algorithm>
# include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void sortInVector(char **list);

	private:
		int _strayInt;
		clock_t vectorStart;
		std::vector<int> _vector;
		std::vector< std::pair<int, int> > _vectorPair;
		void storeInVector(char **list);
		void storeInVectorPair();
		void sortPairVector();
		std::vector< std::pair<int, int> > mergeSort(std::vector< std::pair<int, int> > vectorPair);
		std::vector< std::pair<int, int> > merge(std::vector< std::pair<int, int> > left, std::vector< std::pair<int, int> > right);
		void fillIntoContainer();
		void printVectorStart();
		void printVectorResult();
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
