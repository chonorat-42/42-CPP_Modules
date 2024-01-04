/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:35:45 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/04 01:13:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

int	FileHandler::getData(char *argv[])
{
	fileName = argv[1];
	newFile = fileName + ".replace";
	s1 = argv[2];
	s2 = argv[3];
	if (!fileName.length() || !s1.length() || !s2.length())
		return (0);
	return (1);
}

int	FileHandler::openFile()
{
	std::ifstream	file(fileName);
	std::ofstream	newFile(this->newFile);
	std::string		line;

	if (file.is_open())
	{
		if (newFile.is_open())
		{
			while (std::getline(file, line))
			{
				std::cout << line.find('\0') << std::endl;
				if (line == s1 && line.find("\n") != std::string::npos)
					newFile << s2 << std::endl;
				else if (line == s1)
					newFile << s2;
				else if (line.find("\n") != std::string::npos)
					newFile << line << std::endl;
				else
					newFile << line;
			}
			file.close();
			newFile.close();
		}
		else
		{
			file.close();
			return (0);
		}
	}
	else
		return (0);
	return (1);
}
