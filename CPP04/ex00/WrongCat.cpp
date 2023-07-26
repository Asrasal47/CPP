/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:35:56 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:18:37 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called." << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat& cat) : WrongAnimal(cat)
{
	std::cout << "WrongCat copy constructor called." << std::endl; 
}

WrongCat&	WrongCat::operator=(WrongCat& cat)
{
	std::cout << "WrongCat copy assign operator called." << std::endl; 
	WrongAnimal::operator=(cat);
	return (cat);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meowww meooww meow meow meow" << std::endl;
}
