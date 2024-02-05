/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:59:50 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/05 15:09:14 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T* adress, const size_t length, void (*function)(T&))
{
	for (size_t index = 0; index < length; index++)
		function(adress[index]);
}

template <typename T>
void iter(const T* adress, const size_t length, void (*function)(const T&))
{
	for (size_t index = 0; index < length; index++)
		function(adress[index]);
}

#endif //ITER_HPP
