/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:00:39 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 10:03:34 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;

		PresidentialPardonForm();
	
	public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& src );
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );

		void execute( const Bureaucrat& executor ) const;
};

#endif