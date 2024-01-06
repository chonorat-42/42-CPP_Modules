/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:26:47 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/06 13:53:33 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_H
# define FILEHANDLER_H

# include <iostream>
# include <fstream>
# include <string>

class	FileHandler
{
	public:
		int		getData(char *argv[]);
		int		openFile();
		void	replaceLine(std::string line);

	private:
		std::string		fileName;
		std::string		newFile;
		std::string		s1;
		std::string		s2;
		std::ifstream	infile;
		std::ofstream	outfile;
};

#endif