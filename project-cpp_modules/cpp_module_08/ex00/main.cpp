/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:47:47 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/30 08:52:43 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int>	vec;
	std::vector<int>::iterator	it;

	for (size_t i = 0; i < 10; i++)
		vec.push_back(i * 2);
	it = easyfind(vec, 4);
	std::cout << "iterator for 4: " << *it << std::endl;

	try { it = easyfind(vec, 3); }
	catch (const std::exception &e) { std::cerr << e.what() << '\n'; }
}