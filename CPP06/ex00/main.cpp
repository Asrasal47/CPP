/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:45:59 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 14:09:09 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int			ScalarConverter::_intValue;
char		ScalarConverter::_charValue;
float		ScalarConverter::_floatValue;
double		ScalarConverter::_doubleValue;


int	main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;

	if (argc != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::string	str = std::to_string(INT_MIN);
	ScalarConverter::convert(argv[1]);
	return 0;
}