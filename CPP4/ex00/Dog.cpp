/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:36:45 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 16:06:35 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
}

Dog::Dog(Dog& dog) : Animal(dog)
{
}

Dog&	Dog::operator=(Dog& dog)
{
	Animal::operator=(dog);
	return (dog);
}

Dog::~Dog()
{
}

void	Dog::makeSound() const
{
	std::cout << "Bhoww bhoww bhow bhow bhow" << std::endl;
}
