/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:13:38 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/04 21:18:14 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <limits>
#include <iostream>

int main(void)
{
	Phonebook	book;
	std::string input = "";
	book.welcome();
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0) {
			book.printContacts();
			book.search();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return 0;
}