/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:35:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 19:04:14 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat& cat) : Animal(cat)
{
	_brain = new Brain(*(cat.getBrain()));
}

Cat&	Cat::operator=(Cat& cat)
{
	Animal::operator=(cat);
	_brain = new Brain(*(cat.getBrain()));
	return (cat);
}

Cat::~Cat()
{
	delete(_brain);
}

void	Cat::makeSound() const
{
	std::cout << "Meowww meooww meow meow meow" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return _brain;
}
