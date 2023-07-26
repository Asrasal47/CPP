/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:07:54 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 18:37:23 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int i = 0;
	while (i < 100)
	{
		this->_ideas[i] = "-";
		i++;
	}
}
Brain::Brain(Brain& brain)
{
	int i = 0;
	while (i < 100)
	{
		this->_ideas[i] = brain._ideas[i];
		i++;
	}
}

Brain&	Brain::operator=(Brain& brain)
{
	int i = 0;
	while (i < 100)
	{
		this->_ideas[i] = brain._ideas[i];
		i++;
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index <= 99)
		_ideas[index] = idea;
	else
		std::cout << "Bad index" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	if (index <= 99)
		return _ideas[index];
	else
		std::cout << "Bad index" << std::endl;
	return ("");
}

Brain::~Brain()
{
}