/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:37:38 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 14:41:50 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
			Ice(void);
			Ice(const Ice& other);
			~Ice(void);

			Ice&	operator=(const Ice& other);
			AMateria*	clone() const;
			void		use(ICharacter& target);
};