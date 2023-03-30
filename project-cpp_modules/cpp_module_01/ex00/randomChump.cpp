/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:53:48 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 16:07:33 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a zombie, names it, and it announces itself.
void	randomChump( std::string name ) {
	Zombie zombi( name );
	zombi.announce();
}