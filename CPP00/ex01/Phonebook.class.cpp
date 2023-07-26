/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:37:43 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 17:34:01 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook() :
	_count(0),
	_index(0)
{
}

Phonebook::~Phonebook()
{
}

Contact  Phonebook::get_Contact(int index) const
{
	return this->_contact[index];
}

void	Phonebook::set_Contact(Contact contact)
{
	this->_contact[this->_index] = contact;
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;
	if (this->_count < 8)
		this->_count++;
}

int	Phonebook::get_Count(void)
{
	return this->_count;
}