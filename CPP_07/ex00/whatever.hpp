/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:37:17 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/05 12:56:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& arg1, T& arg2)
{
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template <typename T>
T& min(T& arg1, T& arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}

template <typename T>
T& max(T& arg1, T& arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}

#endif //WHATEVER_HPP
