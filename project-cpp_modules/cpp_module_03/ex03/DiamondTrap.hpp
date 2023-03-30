/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:42:21 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/17 17:04:25 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
			std::string		name;
	public:
			DiamondTrap(const std::string& name);
			DiamondTrap(const DiamondTrap& other);
			DiamondTrap(void);
			~DiamondTrap(void);

			using	ClapTrap::operator=;
			using	ScavTrap::attack;
			void	whoAmI(void);
};