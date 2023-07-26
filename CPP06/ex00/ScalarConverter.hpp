/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:47:11 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 05:44:27 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

# include <string>
# include <iostream>
# include <exception>
#include <iomanip>

enum DataType {
    Unknown,
    Integer,
    Character,
    Float,
    Double
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &copy);
	ScalarConverter	&operator=(ScalarConverter &copy);
	~ScalarConverter();
public:
	static int				_intValue;
	static char				_charValue;
	static float			_floatValue;
	static double			_doubleValue;

	static DataType detectDataType(const std::string& str);
	static void	convert(std::string representation);
	static void	print(const std::string str, const DataType type); 
};

#endif