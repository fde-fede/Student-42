/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:21 by fde-fede           #+#    #+#             */
/*   Updated: 2023/02/02 17:50:09 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
	private:
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
			void			setName(const std::string& target);
			void			setHiPoints(unsigned int hitPoints);
			void			setEnergyPoints(unsigned int energyPoints);
			void			setAttackDamage(unsigned int damage);

			void			attack(const std::string& target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
}