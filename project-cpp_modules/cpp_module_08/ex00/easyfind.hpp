/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:47:56 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/30 08:49:39 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>

class outrange : public std::exception{
public:
	const char *what() const throw()
	{
		return "Out of range";
	}
};

template <typename T>
typename T::iterator	easyfind(T &p1, int p2){
	typename T::iterator ret = std::find(p1.begin(), p1.end(), p2);
	if (ret == p1.end())
		throw outrange();
	return ret;
}