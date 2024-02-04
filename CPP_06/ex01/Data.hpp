/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:06:31 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/04 16:18:27 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	public:
		Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
		int getValue()const;
		void setValue(int value);

	private:
		int _value;
};

#endif //DATA_HPP
