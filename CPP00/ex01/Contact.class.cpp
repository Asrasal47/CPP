/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:02:06 by arasal            #+#    #+#             */
/*   Updated: 2023/03/28 19:12:25 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact() : 
	_f_name(""),
	_l_name(""),
	_n_name(""),
	_p_number(""),
	_darkest_secret("")
{
}

Contact::~Contact()
{
}

void	Contact::set_f_name(const std::string f_name)
{
	this->_f_name = f_name;
}

void	Contact::set_l_name(const std::string l_name)
{
	this->_l_name = l_name;
}

void	Contact::set_n_name(const std::string n_name)
{
	this->_n_name = n_name;
}

void	Contact::set_p_number(const std::string p_number)
{
	this->_p_number = p_number;
}

void	Contact::set_darkest_secret(const std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string Contact::get_f_name() const
{
	return this->_f_name;
}

std::string Contact::get_l_name() const
{
	return this->_l_name;
}

std::string Contact::get_n_name() const
{
	return this->_n_name;
}

std::string Contact::get_p_number() const
{
	return this->_p_number;
}

std::string Contact::get_darkest_secret() const
{
	return this->_darkest_secret;
}
