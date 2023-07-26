/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:35:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:25:35 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called." << std::endl; 
}

Cat&	Cat::operator=(Cat& cat)
{
	std::cout << "Cat copy assign operator called." << std::endl; 
	Animal::operator=(cat);
	return (cat);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meowww meooww meow meow meow" << std::endl;
}
