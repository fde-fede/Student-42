/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:21 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/04 21:00:52 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_Secret;
	int			_Index;

	std::string	_printLen(std::string	str) const;
	std::string	_getInput(std::string	str) const;

public:
	Contact();
	~Contact();
	void	init(void);
	void	view(int index) const;
	void	display(int index) const;
	void	setIndex(int i);
};

#endif