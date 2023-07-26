/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:50:00 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 14:43:58 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <float.h>
#include <sstream>
#include <string.h>


ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter& copy)
{
	(void)copy;
	std::cout << "ScalarConverter copy constructor called." << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter& copy)
{
	(void)copy;
	std::cout << "ScalarConverter copy assign constructor called." << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}


bool isInteger(const std::string& str) {
    if (str.empty())
        return false;

    std::string::const_iterator it = str.begin();
    if (*it == '-' || *it == '+')
        ++it;

    while (it != str.end() && std::isdigit(*it))
        ++it;

    return it == str.end();
}

bool isCharacter(const std::string& str) {
    return str.length() == 1;
}

bool isFloat(std::string str) {
    if (str.empty())
        return false;

    char suffix = 'k';
	const char* dot = strchr(str.c_str(), '.');
	if (dot == NULL) return false;
	if (*(dot + 1) == '\0' || *(dot + 1) == 'f' || *(dot + 1) == 'F' ) return false;
	const char* dot2 = strchr(dot + 1, '.');
	if (dot2 != NULL) return false;
	if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
	{
		suffix = 'f';
		str.erase(str.length() - 1);
	}
    std::istringstream iss(str);
    float floatValue;
	 if (suffix == 'f' && iss >> floatValue )
        return true;
	return false;
}

bool isDouble(const std::string& str) {
    if (str.empty())
        return false;

	const char* dot = strchr(str.c_str(), '.');
	if (dot == NULL) return false;
	if (*(dot + 1 )== '\0') return false;
	const char* dot2 = strchr(dot + 1, '.');
	if (dot2 != NULL) return false;

    std::istringstream iss(str);
    double doubleValue;

    return (iss >> doubleValue && iss.eof());
}

int	infinity(std::string str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "NaN" || str == "+inff"
		|| str == "-inff" || str == "nanf" || str == "NaNf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str;
		if (!(str == "+inff" || str == "-inff" || str == "nanf" || str == "NaNf"))
			std::cout << "f";
		std::cout << std::endl;
		std::cout << "double: ";
		if (str == "+inff" || str == "-inff" || str == "nanf" || str == "NaNf")
			str.erase(str.length() - 1);
		std::cout << str << std::endl;
		return 1;
	}
	return 0;
}

DataType ScalarConverter::detectDataType(const std::string& str)
{
	if (isInteger(str))
        return Integer;
    if (isCharacter(str))
        return Character;
    if (isFloat(str))
		return Float;
    if (isDouble(str))
        return Double;;
    return Unknown;
}

void	ScalarConverter::convert(std::string str)
{
	if (infinity(str))
		return ;
	DataType type = detectDataType(str);
	if (type == Unknown)
	{
		std::cout << "Unknown type, can't convert to shit" << std::endl;
		return ;
	}
	if (type == Character)
	{
    	_charValue = str[0];
        _intValue = static_cast<int>(_charValue);
        _floatValue = static_cast<float>(_charValue);
        _doubleValue = static_cast<double>(_charValue);
	}
	if (type == Integer)
	{
		std::istringstream iss(str);
		iss >> _intValue;
        _charValue = static_cast<char>(_intValue);
        _floatValue = static_cast<float>(_intValue);
        _doubleValue = static_cast<double>(_intValue);
	}
	if (type == Float)
	{
		if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
			str.erase(str.length() - 1);
    	std::istringstream iss(str);
		iss >> _floatValue;
        _intValue = static_cast<int>(_floatValue);
        _doubleValue = static_cast<double>(_floatValue);
        _charValue = static_cast<char>(_floatValue);
	}
	if (type == Double)
	{
		std::istringstream iss(str);
		iss >> _doubleValue;
        _charValue = static_cast<char>(_doubleValue);
        _intValue = static_cast<int>(_doubleValue);
        _floatValue = static_cast<float>(_doubleValue);
	}
	print(str, type);
}

void	ScalarConverter::print(const std::string str, const DataType type)
{
	if (std::isprint(_intValue))
		std::cout << "char: " << _charValue << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::string	s_value = std::string(str);
	std::string	d_value = std::to_string(_floatValue).substr(0, s_value.size());
	if (s_value != std::to_string(_intValue) && s_value != d_value && type != Character)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << _intValue << std::endl;
	std::cout << std::fixed << std::setprecision(10);
	d_value = std::to_string(_floatValue).substr(0, s_value.size());
	if (s_value != d_value && type == Integer)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << _floatValue << "f" << std::endl;
	d_value = std::to_string(_doubleValue).substr(0, s_value.length());
	if (s_value != d_value && type == Integer)
		std::cout << "double: " << "impossible" << std::endl;
	else
		std::cout << "double: " << _doubleValue << std::endl;
}

