/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:01:02 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 17:12:16 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	data = {"hello", 42};
	std::cout << &data << std::endl;
	std::cout << Serializer::serialize(&data) << std::endl;
	std::cout << *Serializer::deserialize(Serializer::serialize(&data));
	std::cout << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;
	return 0;
}