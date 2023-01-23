/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:46:33 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 12:01:10 by fde-fede         ###   ########.fr       */
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
		Zombie( std::string name );
		~Zombie();
		void	announce( void );
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );

};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif