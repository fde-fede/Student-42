/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:18:06 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 17:23:26 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;
		HumanA();
	
	public:
	HumanA( std::string name, Weapon& weapon );
	~HumanA();

	void	attack( void ) const;
};