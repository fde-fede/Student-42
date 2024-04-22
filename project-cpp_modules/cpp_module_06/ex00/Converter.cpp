/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:03:46 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/17 15:03:49 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

ScalarConverter::ScalarConverter(void) {
	this->_c = '\0';
	this->_n = 0;
	this->_f = 0.0f;
	this->_d = 0.0;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs){
	if (this != &rhs) {
		this->_n = rhs.getI();
		this->_f = rhs.getF();
		this->_c = rhs.getC();
	}
	return *this;
}

char	ScalarConverter::getC(void) const {
	return this->_c;
}

void	ScalarConverter::setC(char c) {
	this->_c = c;
}

bool	ScalarConverter::isLiterals(void) const{
	if ((_impossible) || (_str.compare("nan") == 0) || (_str.compare("nanf") == 0)
	|| (_str.compare("+inf") == 0) || (_str.compare("+inff") == 0)
	|| (_str.compare("-inf") == 0) || (_str.compare("-inff") == 0)
	|| (_str.compare("-inff") == 0) || (_str.compare("-inff") == 0)
	|| (_str.compare("+inff") == 0) || (_str.compare("+inff") == 0))
	{
		return true;
	}
	return false;
}

void	ScalarConverter::printChar(void) const {
	if (this->isLiterals() || (!std::isprint(_n) && (_n >= 127))) {
		std::cout << "Impossible";
	}
	else if (!std::isprint(this->_n)){
		std::cout << "Non displayable";
	}
	else {
		std::cout << "'" << getC() << "'";
	}
	std::cout << std::endl;
}

int ScalarConverter::getI(void) const {
	return this->_n;
}

void ScalarConverter::setI(int n) {
	this->_n = n;
}

void ScalarConverter::printInt(void) const {
	if (this->isLiterals() || _impossible) {
		std::cout << "Impossible";
	}
	else {
		std::cout << getI();
	}
	std::cout << std::endl;
}

float ScalarConverter::getF(void) const {
	return this->_f;
}

void ScalarConverter::setF(float f) {
	this->_f = f;
}

double	ScalarConverter::getD(void) const {
	return this->_d;
}

void ScalarConverter::setD(double d) {
	this->_d = d;
}

std::string	ScalarConverter::getStr(void) const {
	return this->_str;
}

void ScalarConverter::setStr(std::string str) {
	this->_str = str;
	this->setType();
	if (getType() == NONE) {
		throw ScalarConverter::ConverterException();
	}
}

e_type ScalarConverter::getType(void) const {
	return this->_type;
}

bool ScalarConverter::isChar(void) const {
	return _str.length() == 1 && std::isalpha(_str[0]) && std::isprint(_str[0]);
}

bool ScalarConverter::isInt(void) const {
	int	j = 0;
	if (_str[j] == '-' || _str[j] == '+') {
		j++;
	}
	for (int i(j); i < (int) _str.length(); i++) {
		if (!std::isdigit(_str[i])) {
			return false;
		}
	}
	return true;
}

bool ScalarConverter::isDouble(void) const {
	if (_str.find('.') == std::string::npos || _str.find('.') == 0
	|| _str.find('.') == _str.length() - 1) {
		return false;
	}
	int	j = 0;
	int found = 0;
	if (_str[j] == '-' || _str[j] == '+') {
		j++;
	}
	for (int i(j); i < (int) _str.length(); i++) {
		if (_str[i] == '.') {
			found++;
		}
		if ((!std::isdigit(_str[i]) && _str[i] != '.') || found > 1) {
			return false;
		}
	}
	return true;
}

bool	ScalarConverter::isFloat(void) const {
	if (_str.find('.') == std::string::npos || _str.back() != 'f'
	|| _str.find('.') == 0 || _str.find('.') == _str.length() - 2) {
		return false;
	}
	int found = 0;
	int j = 0;
	if (_str[j] == '-' || _str[j] == '+') {
		j++;
	}
	for (int i(j); i < (int) _str.length() - 1; i++) {
		if (_str[i] == '.') {
			found++;
		}
		if ((!std::isdigit(_str[i]) && _str[i] != '.') || found > 1) {
			return false;
		}
	}
	return true;
}

void	ScalarConverter::printFloat(void) const {
	if (_str.compare("nan") == 0 || _str.compare("nanf") == 0) {
		std::cout << "nanf";
	}
	else if (_str.compare("+inf") == 0 || _str.compare("+inff") == 0) {
		std::cout << "+inff";
	}
	else if (_str.compare("-inf") == 0 || _str.compare("-inff") == 0) {
		std::cout << "-inff";
	}
	else if (_impossible) {
		std::cout << "Impossible";
	}
	else {
		if (_f - static_cast<int>(_f) == 0) {
			std::cout << _f << ".0f";
		}
		else {
			std::cout << getF() << "f";
		}
	}
	std::cout << std::endl;
}

void	ScalarConverter::printDouble(void) const {
	if (_str.compare("nan") == 0 || _str.compare("nanf") == 0) {
		std::cout << "nan";
	}
	else if (_str.compare("+inf") == 0 || _str.compare("+inff") == 0) {
		std::cout << "+inf";
	}
	else if (_str.compare("-inf") == 0 || _str.compare("-inff") == 0) {
		std::cout << "-inf";
	}
	else if (_impossible) {
		std::cout << "Impossible";
	}
	else {
		if (_d - static_cast<int>(_d) == 0) {
			std::cout << _d << ".0";
		}
		else {
			std::cout << getD() << "f";
		}
	}
	std::cout << std::endl;
}

void	ScalarConverter::setType(void) {
	if (isChar()) {
		_type = CHAR;
	}
	else if (isInt()) {
		_type = INT;
	}
	else if (isFloat()) {
		_type = FLOAT;
	}
	else if (isDouble()) {
		_type = DOUBLE;
	}
	else if (isLiterals()) {
		_type = LITERALS;
	}
	else {
		_type = NONE;
	}
}

bool	ScalarConverter::isImpossible(void) {
	try {
		if (_type == INT) {
			_n = std::stoi(_str);
		}
		else if (_type == FLOAT) {
			_f = std::stof(_str);
		}
		else if (_type == DOUBLE) {
			_d = std::stod(_str);
		}
	}
	catch (std::exception &e) {
		_impossible = true;
		return true;
	}
	return false;
}

void	ScalarConverter::convert(void) {
	if (isImpossible())
		return;
	switch (_type) {
		case CHAR:
			_c = _str[0];
			_n = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break;
		case INT:
			_n = std::stoi(_str);
			_c = static_cast<char>(_n);
			_f = static_cast<float>(_n);
			_d = static_cast<double>(_n);
			break;
		case FLOAT:
			_f = std::stof(_str);
			_n = static_cast<int>(_f);
			_c = static_cast<char>(_f);
			_d = static_cast<double>(_f);
			break;
		case DOUBLE:
			_d = std::stod(_str);
			_n = static_cast<int>(_d);
			_c = static_cast<char>(_d);
			_f = static_cast<float>(_d);
			break;
		default:
			break;
	}
}

std::ostream& operator<<(std::ostream& out, const ScalarConverter& c) {
	out << "char: ";
	c.printChar();
	out << "int: ";
	c.printInt();
	out << "float: ";
	c.printFloat();
	out << "double: ";
	c.printDouble();
	return out;
}