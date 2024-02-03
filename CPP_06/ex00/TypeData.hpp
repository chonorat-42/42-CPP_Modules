/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeData.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:27:19 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/03 15:46:26 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDATA_HPP
# define TYPEDATA_HPP

class TypeData
{
	public:
		TypeData(char character, int integer, float floating, double doublePrecision);
		~TypeData();
		char getCharacter() const;
		int getInteger() const;
		float getFloating() const;
		double getDoublePrecision() const;

	private:
		char character;
		int integer;
		float floating;
		double doublePrecision;
		TypeData();
		TypeData(const TypeData& other);
		TypeData& operator=(const TypeData& other);
};

#endif //TYPEDATA_HPP
