/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:34:59 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 17:38:27 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void	HumanA::attack( void ) const {
	if (this->_weapon.getType() != "") {
		std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
	} else {
		std::cout << _name << " doesn't have a weapon to attack." << std::endl;
	}
}