/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:54 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/10 12:35:18 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void storeCSVData();

	private:
		std::map<std::string, float> bitcoinData;
		bool storeInMap(std::string& line, size_t position);
		class CannotOpenCSV : public std::exception
		{
			public:
				const char *what()const throw();
		};
		class CSVInvalidFormat : public std::exception
		{
			public:
				const char *what()const throw();
		};
};

#endif //BITCOINEXCHANGE_HPP
