/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:29:32 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/20 12:30:33 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

void iterfun(int &a)
{
	a *= 2;
}

void iterfun(std::string &s)
{
	s = "Kardesim o mallocu yanlis yapiyosun";
}

int	main()
{
	int	a[12];

	for (size_t i = 0; i < 12; i++)
	{
		a[i] = i * 2;
		std::cout << a[i] << " ";
	}
	iter(a, 12, &iterfun);
	std::cout << std::endl;
	for (size_t i = 0; i < 12; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	std::string str[6];
	iter(str, 6, &iterfun);
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << str[i] << std::endl;
	}
}