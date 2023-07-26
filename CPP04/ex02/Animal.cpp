/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:20:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:44:32 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal")
{
	std::cout << "Default animal constructor called." << std::endl; 
}
Animal::Animal(Animal& animal) : _type(animal._type)
{
	std::cout << "Animal copy constructor called." << std::endl; 
}

Animal&	Animal::operator=(Animal& animal)
{
	std::cout << "Animal copy assign operator called." << std::endl; 
	_type = animal._type;
	return (*this);
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
	std::cout << "Animal Destructor called." << std::endl; 
}