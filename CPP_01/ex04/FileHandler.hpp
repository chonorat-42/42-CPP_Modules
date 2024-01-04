/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:26:47 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/04 01:13:08 by chonorat         ###   ########.fr       */
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
		int	getData(char *argv[]);
		int	openFile();

	private:
		std::string	fileName;
		std::string	newFile;
		std::string	s1;
		std::string	s2;
};

#endif