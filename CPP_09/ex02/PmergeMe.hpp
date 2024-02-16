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
# include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void sortInVector(char **list);
		void sortInDeque(char **list);
		void printResult();

	private:
		int _strayInt;
		clock_t _vectorStart;
		double _vectorExecTime;
		clock_t _dequeStart;
		double _dequeExecTime;
		std::vector<int> _vector;
		std::vector< std::pair<int, int> > _vectorPair;
		std::deque<int> _deque;
		std::deque< std::pair<int, int> > _dequePair;
		void storeInVector(char **list);
		void storeInDeque(char **list);
		void storeInVectorPair();
		void storeInDequePair();
		void sortPairVector();
		void sortPairDeque();
		std::vector< std::pair<int, int> > mergeSort(std::vector< std::pair<int, int> > vectorPair);
		std::deque< std::pair<int, int> > mergeSort(std::deque< std::pair<int, int> > dequePair);
		std::vector< std::pair<int, int> > merge(std::vector< std::pair<int, int> > left, std::vector< std::pair<int, int> > right);
		std::deque< std::pair<int, int> > merge(std::deque< std::pair<int, int> > left, std::deque< std::pair<int, int> > right);
		void fillIntoVector();
		void fillIntoDeque();
		void printStartList();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		class InvalidInteger : public std::exception
		{
			public:
				InvalidInteger(const std::string& arg);
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
