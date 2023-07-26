/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:36:45 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:26:13 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog& dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called." << std::endl; 
}

Dog&	Dog::operator=(Dog& dog)
{
	std::cout << "Dog copy assign operator called." << std::endl; 
	Animal::operator=(dog);
	return (dog);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Bhoww bhoww bhow bhow bhow" << std::endl;
}
