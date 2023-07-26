/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:20:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 16:04:51 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("animal")
{
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal& animal) : _type(animal._type)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl; 
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal& animal)
{
	std::cout << "WrongAnimal copy assign operator called." << std::endl; 
	_type = animal._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Peeew peeeeew pew pew pew" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::setType(std::string typ)
{
	_type = typ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called." << std::endl; 
}