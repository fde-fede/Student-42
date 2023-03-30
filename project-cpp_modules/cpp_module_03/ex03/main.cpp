/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:03 by fde-fede           #+#    #+#             */
/*   Updated: 2023/02/02 17:59:26 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	Diamond("Daniel");

	Diamond.attack("Pirates");
	Diamond.attack("Kings");
	Diamond.attack("Lions");
	Diamond.beRepaired(10);
	Diamond.takeDamage(100);
	Diamond.guardGate();
	Diamond.highFivesGuys();
	Diamond.whoAmI();
}