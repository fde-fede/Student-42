/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:29:36 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 09:49:43 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		Form();
	
	public:
		Form( const std::string& name, int gradeToSign );
		Form( const std::string& name, int gradeToSign, int gradeToExecute );
		Form( const Form& src );
		~Form();

		Form&	operator=( const Form& rhs );

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned( const Bureaucrat& bureaucrat );
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too low"; }
		};
};

std::ostream&	operator<<( std::ostream& o, const Form& rhs );

#endif