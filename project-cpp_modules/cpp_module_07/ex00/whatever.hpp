/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:22:20 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/20 12:25:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T1>
void swap(T1 &a, T1 &b) {
	T1	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T1>
T1	min(T1 a, T1 b) {
	if (a < b)
		return a;
	return b;
}

template<typename T1>
T1	max(T1 a, T1 b) {
	if (a > b)
		return a;
	return b;
}