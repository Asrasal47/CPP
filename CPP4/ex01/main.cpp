/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:48:48 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 18:57:36 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat(*cat1);
	Brain*	brain1 = cat1->getBrain();
	Brain*	brain2 = cat2->getBrain();

	brain1->setIdea(0, "lets throw a party");
	std::cout << std::endl;
	std::cout << "cat1 first idea " << brain1->getIdea(0) << std::endl;
	std::cout << "cat2 first idea " << brain2->getIdea(0) << std::endl;
	std::cout << std::endl;
	delete cat1;
	delete cat2;
}