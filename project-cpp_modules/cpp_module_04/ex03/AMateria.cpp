/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:11:46 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 11:12:42 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::~AMateria(void) {}

const std::string&	AMateria::getType(void) const
{
	return (this->type);
}