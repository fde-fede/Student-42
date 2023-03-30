/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:12:22 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 16:20:36 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie *zombiz = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombiz[i].setName(name);
	}
	return zombiz;
}