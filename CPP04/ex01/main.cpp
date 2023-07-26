/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:48:48 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:42:22 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"


int	main(void)
{
	Animal *zoo[100];

	for(int i = 0; i < 100; i++)
	{
		if (i < 100 / 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
		std::cout << std::endl;
	}

	for(int i = 0; i < 100; i++)
	{
		delete(zoo[i]);
		std::cout << std::endl;
	}
	return (0);
}
