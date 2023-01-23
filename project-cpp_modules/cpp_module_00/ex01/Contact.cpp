/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:20:56 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/10 11:48:50 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const
{
	std::string	input = "";
	bool		valid = false;
	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input; please try again." << std::endl;
		}
	} while (!valid);
	return (input);
}

void	Contact::init(void) {
	std::cin.ignore();
	this->_FirstName = this->_getInput("Please enter your first name: ");
	this->_LastName = this->_getInput("Please enter your last name: ");
	this->_Nickname = this->_getInput("Please enter your nickname: ");
	this->_PhoneNumber = this->_getInput("Please enter your phone number: ");
	this->_Secret = this->_getInput("Please enter your darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::setIndex(int i) {
	this->_Index = i;
}

void	Contact::view(int index) const {
	if (this->_FirstName.empty() || this->_LastName.empty() || this->_Nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_FirstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_LastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_Nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display(int index) const
{
	if (this->_FirstName.empty() || this->_LastName.empty() || this->_Nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
	std::cout << "First Name:\t" << this->_FirstName << std::endl;
	std::cout << "Last Name:\t" << this->_LastName << std::endl;
	std::cout << "Nickname:\t" << this->_Nickname << std::endl;
	std::cout << std::endl;
}