/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:35:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:36:05 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
:
_brain(new Brain())
{
	std::cout << "Cat constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat& cat) : Animal(cat), _brain(new Brain(*cat._brain))
{
	std::cout << "Cat copy constructor called." << std::endl; 
}

Cat&	Cat::operator=(Cat& cat)
{
	std::cout << "Cat copy assign operator called." << std::endl; 
	Animal::operator=(cat);
	*_brain = *cat._brain;
	return (cat);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meowww meooww meow meow meow" << std::endl;
}
