/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:13:04 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 16:16:36 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie();
		~Zombie();
		void	announce( void );
		Zombie*	newZombie( std::string name );
		void	setName( std::string name );
};

Zombie*	zombieHorde( int N, std::string name );

#endif