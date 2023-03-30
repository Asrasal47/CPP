/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:50 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 00:44:33 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string typ) : type(typ)
{
}


Weapon::~Weapon()
{
}

const std::string&	Weapon::getType(void)
{
	const std::string& r = this->type;
	return r;
}

void	Weapon::setType(std::string typ)
{
	this->type = typ;
}
