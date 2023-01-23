/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:34 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 17:34:32 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {
}

void	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const {
	if (this->_weapon != NULL && this->_weapon->getType() != "") {
		std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	} else {
		std::cout << _name << " doesn't have a weapon to attack." << std::endl;
	}
}