/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:38:05 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 06:49:46 by arasal           ###   ########.fr       */
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
	Fixed(const Fixed & num);
	~Fixed();

	Fixed& operator=(Fixed const &num);

	int		getRawBits(void) const;
	void 	setRawBits(int	const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const &num);

#endif