/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:33:17 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/18 14:03:36 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
			FragTrap(const std::string& name);
			FragTrap(const FragTrap& other);
			FragTrap(void);
			~FragTrap(void);

			using	ClapTrap::operator=;
			void	highFivesGuys(void) const;			
};