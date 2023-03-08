/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:03:42 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/16 19:37:25 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(){
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mday
				<< "_"
				<< std::setw(2) << 1 + std::localtime(&result)->tm_hour
				<< std::setw(2) << 1 + std::localtime(&result)->tm_min
				<< std::setw(2) << 1 + std::localtime(&result)->tm_sec
				<< "] " << std::flush;
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	this->_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
			<< "amount:" << _amount << ";"
			<< "nb_deposit:" << _nbDeposits << std::endl;
}

void	Account::makeWithdrawal( int withdrawal ) {
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";"
			<< "withdrawal:" << std::flush;
	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::flush;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";"
			<< "nb_deposit:" << _nbDeposits << std::endl;
	return true;
}

int Account::checkAmount( void ) const {
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals << std::endl;
}