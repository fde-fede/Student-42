/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:29:36 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/10 12:05:59 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	public:
		/* Constructors & Destructors */
		Form(void);
		Form(std::string const &name, int const &signGrade, int const &execGrade);
		Form(Form const &copy);
		virtual ~Form(void);

		/* Basic Operators */
		Form const	&operator=(Form const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getSignGrade(void) const;
		int const			&getExecGrade(void) const;

		/* Main Member Functions */
		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;

		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);
