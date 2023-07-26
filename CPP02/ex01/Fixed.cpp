/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:37:50 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 06:52:06 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
:
_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	_value = i << _fbits;
}

Fixed::Fixed(const float i)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(i * (1 << _fbits));
}

Fixed& Fixed::operator= (Fixed const &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = num.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
