/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:21:16 by arasal            #+#    #+#             */
/*   Updated: 2023/03/29 23:29:00 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string a = "HI THIS IS BRAIN";
	std::string* stringPTR = &a;
	std::string& stringREF = a;

	std::cout << &a << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << a << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}