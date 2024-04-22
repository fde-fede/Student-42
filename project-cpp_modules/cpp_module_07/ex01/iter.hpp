/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:29:34 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/20 12:30:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	iter(T arr[], size_t len, void (fun)(T &)) {
	for (size_t i = 0; i < len; i++)
	{
		fun(arr[i]);
	}
}