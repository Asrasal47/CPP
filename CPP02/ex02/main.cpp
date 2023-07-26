/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:48:26 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 14:37:28 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    //custom tests
   std::cout << "min: " << Fixed::min( a, b ) << std::endl;
   std::cout << "sum: " << a + b << std::endl;
   std::cout << "a - b: " << a - b << std::endl;
   std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
   std::cout << "a--: " << a-- << std::endl;
   std::cout << "a: " << a << std::endl;
   std::cout << "--a; " << --a << std::endl;
    return 0;
}
