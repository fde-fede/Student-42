/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:24:12 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 17:25:42 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	this->setType(type);
}

Weapon::~Weapon() {
}

const	std::string& Weapon::getType( void ) {
	return this->type;
}

void	Weapon::setType( std::string newType ) {
	this->type = newType;
}