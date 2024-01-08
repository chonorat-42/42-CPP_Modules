/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:35:45 by chonorat          #+#    #+#             */
/*   Updated: 2024/01/08 12:42:41 by chonorat         ###   ########lyon.fr   */
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

void	FileHandler::replaceLine(std::string line)
{
	size_t	index = 0;
	size_t	pos = 0;

	while (index < line.size())
	{
		if ((pos = line.find(s1, index)) != std::string::npos)
		{
			if (pos > index)
				outfile << line.substr(index, pos - index);
			outfile << s2;
			index = pos + s1.size();
		}
		else
		{
			outfile << line.substr(index, line.size() - index);
			break;
		}
	}
	outfile << std::endl;
}

int	FileHandler::openFile()
{
	std::string	line;

	infile.open(fileName.c_str(), std::ios::in);
	if (infile.is_open())
	{
		outfile.open(newFile.c_str(), std::ios::out | std::ios::trunc);
		if (outfile.is_open())
		{
			while (std::getline(infile, line))
				replaceLine(line);
			infile.close();
			outfile.close();
		}
		else
			return (infile.close(), 0);
	}
	else
		return (0);
	return (1);
}
