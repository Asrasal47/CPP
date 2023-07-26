/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:18:01 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 06:50:22 by arasal           ###   ########.fr       */
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
	Fixed(const Fixed & num);
	~Fixed();

	Fixed& operator=(Fixed const &num);

	int	getRawBits(void) const;
	void setRawBits(int	const raw);
};


#endif