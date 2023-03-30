/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:58:13 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 11:13:55 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string	type;
	
	public:
		AMateria(const std::string& type);
		virtual ~AMateria(void);

		virtual const std::string&	getType(void) const;
		virtual AMateria*			clone() const = 0;
		virtual void				use(ICharacter& target) = 0;
};