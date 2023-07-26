/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:08:03 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 15:09:50 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nam) : name(nam), w(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (!w)
		std::cout << this->name << " attacks with no weapon :'(" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& we)
{
	this->w = &we;
}
