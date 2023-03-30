/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:35:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 16:06:28 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
}

Cat::Cat(Cat& cat) : Animal(cat)
{
}

Cat&	Cat::operator=(Cat& cat)
{
	Animal::operator=(cat);
	return (cat);
}

Cat::~Cat()
{
}

void	Cat::makeSound() const
{
	std::cout << "Meowww meooww meow meow meow" << std::endl;
}
