/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:20:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 16:04:51 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal")
{
}
Animal::Animal(Animal& animal) : _type(animal._type)
{
}

Animal&	Animal::operator=(Animal& animal)
{
	_type = animal._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Peeew peeeeew pew pew pew" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string typ)
{
	_type = typ;
}

Animal::~Animal()
{
}