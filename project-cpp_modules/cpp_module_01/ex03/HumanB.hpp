/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:20:26 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 17:23:17 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon*		_weapon;
		
	public:
		HumanB( std::string name );
		~HumanB();

		void	attack( void ) const;
		void	setWeapon( Weapon& weapon );
};