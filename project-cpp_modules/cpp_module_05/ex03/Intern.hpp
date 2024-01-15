/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:54:35 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 13:03:18 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {

	public:
		Intern();
		Intern( const Intern& src );
		~Intern();

		Intern& operator=( const Intern& rhs );

		Form*	makeForm( std::string name, std::string target );
};

#endif