/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:53:25 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/18 14:04:33 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
			ScavTrap(const std::string& name);
			ScavTrap(const ScavTrap& other);
			ScavTrap(void);
			~ScavTrap(void);

			using	ClapTrap::operator=;
			void	attack(const std::string& target);
			void	guardGate(void) const;
};