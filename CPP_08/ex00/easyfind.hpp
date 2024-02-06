/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:13:04 by chonorat          #+#    #+#             */
/*   Updated: 2024/02/06 18:31:28 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
bool easyfind(T arg, int integer)
{
	typename T::iterator it = std::find(arg.begin(), arg.end(), integer);
	if (it != arg.end())
		return (true);
	return (false);
}

#endif //EASYFIND_HPP
