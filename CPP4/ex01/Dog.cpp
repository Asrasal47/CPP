/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:36:45 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 19:05:14 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog& dog) : Animal(dog)
{
	_brain = new Brain(*(dog.getBrain()));
}

Dog&	Dog::operator=(Dog& dog)
{
	Animal::operator=(dog);
	_brain = new Brain(*(dog.getBrain()));
	return (dog);
}

Dog::~Dog()
{
	delete(_brain);
}

void	Dog::makeSound() const
{
	std::cout << "Bhoww bhoww bhow bhow bhow" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return _brain;
}
