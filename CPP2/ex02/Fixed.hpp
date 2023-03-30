/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:38:05 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 07:17:10 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{

private:

	int	_value;
	static int const _fbits = 8;

public:

	Fixed();
	Fixed(const int i);
	Fixed(const float i);
	Fixed(const Fixed& num);
	~Fixed();

	Fixed&	operator=(Fixed const &num);
	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	operator+ (const Fixed& num);
	Fixed	operator- (const Fixed& num);
	Fixed	operator* (const Fixed& num);
	Fixed	operator/ (const Fixed& num);
	bool	operator< (const Fixed& num);
	bool	operator> (const Fixed& num);
	bool	operator<= (const Fixed& num);
	bool	operator>= (const Fixed& num);
	bool	operator== (const Fixed& num);
	bool	operator!= (const Fixed& num);


	int		getRawBits(void) const;
	void 	setRawBits(int	const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed& 		min(Fixed& num1, Fixed& num2);
	static Fixed& 		max(Fixed& num1, Fixed& num2);
	const static Fixed& min(const Fixed& num1, const Fixed& num2);
	const static Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& o, Fixed const &num);

#endif