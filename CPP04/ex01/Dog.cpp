/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:36:45 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:36:12 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
:
_brain(new Brain())
{
	std::cout << "Dog constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog& dog) : Animal(dog), _brain(new Brain(*dog._brain))
{
	std::cout << "Dog copy constructor called." << std::endl; 
}

Dog&	Dog::operator=(Dog& dog)
{
	std::cout << "Dog copy assign operator called." << std::endl; 
	Animal::operator=(dog);
	*_brain = *dog._brain;
	return (dog);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "Bhoww bhoww bhow bhow bhow" << std::endl;
}
