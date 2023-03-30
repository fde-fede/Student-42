/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:52:55 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 12:07:35 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a zombie, names it, and return it so we can use it outside the function scope.
Zombie*	newZombie( std::string name ) {
	return (new Zombie( name ));
}