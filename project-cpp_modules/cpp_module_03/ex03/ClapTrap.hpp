/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:20 by fde-fede           #+#    #+#             */
/*   Updated: 2023/02/02 17:57:10 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
	protected:
			std::string		name;
			unsigned int	hitPoints;
			unsigned int	energyPoints;
			unsigned int	attackDamage;
	public:
			ClapTrap(void);
			ClapTrap(const ClapTrap& other);
			ClapTrap(std::string name);
			~ClapTrap(void);	

			ClapTrap&		operator=(const ClapTrap& other);
			
			const std::string&	getName(void) const;
			unsigned int	getHitPoints(void) const;
			unsigned int	getEnergyPoints(void) const;
			unsigned int	getAttackDamage(void) const;
			void			setName(const std::string& name);
			void			setHitPoints(unsigned int hitPoints);
			void			setEnergyPoints(unsigned int energyPoints);
			void			setAttackDamage(unsigned int damage);

			void			attack(const std::string& target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
};