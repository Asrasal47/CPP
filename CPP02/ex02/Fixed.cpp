/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:37:50 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 14:54:55 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
:
_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & num)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = i << _fbits;
}

Fixed::Fixed(const float i)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(i * (1 << _fbits));
}

Fixed& Fixed::operator= (Fixed const &num)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	_value = num.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return(float(_value) / (1 << _fbits));
}

int	Fixed::toInt(void) const
{
	return(_value >> _fbits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed &num)
{
	stream << num.toFloat();
	return (stream);
}

bool	Fixed::operator< (const Fixed& num)
{
	if(_value < num._value)
		return (true);
	return (false);
}

bool	Fixed::operator> (const Fixed& num)
{
	if(_value > num._value)
		return (true);
	return (false);
}

bool	Fixed::operator<= (const Fixed& num)
{
	if(_value <= num._value)
		return (true);
	return (false);
}
bool	Fixed::operator>= (const Fixed& num)
{
	if(_value >= num._value)
		return (true);
	return (false);
}

bool	Fixed::operator== (const Fixed& num)
{
	if(_value == num._value)
		return (true);
	return (false);
}
bool	Fixed::operator!= (const Fixed& num)
{
	if(this->_value != num._value)
		return (true);
	return (false);
}

Fixed	Fixed::operator+ (const Fixed& num)
{
	this->_value += num._value;
	return *this;
}

Fixed	Fixed::operator- (const Fixed& num)
{
	this->_value -= num._value;
	return *this;
}

Fixed	Fixed::operator* (const Fixed& num)
{
	Fixed temp;
	temp.setRawBits((this->_value * num._value) >> _fbits);
	return temp;
}

Fixed	Fixed::operator/ (const Fixed& num)
{
	Fixed	temp;

	temp.setRawBits(this->toFloat() / num.toFloat());
	return (temp);
}

Fixed&	Fixed::operator++ (void)
{
	++_value;
	return (*this);
}

Fixed&	Fixed::operator-- (void)
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator++ (int)
{
	Fixed temp;

	temp = *this;
	++_value;
	return (temp);
}

Fixed	Fixed::operator-- (int)
{
	Fixed temp = *this;

	--_value;
	return (temp);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}
