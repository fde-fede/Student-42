/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:22:03 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 16:23:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 4

int main( void ) {
	Zombie *zombiz = zombieHorde(N, "zombi");

	for (size_t i = 0; i < N; i++) {
		zombiz[i].announce();
	}
	
	delete [] zombiz;
	return 0;
}