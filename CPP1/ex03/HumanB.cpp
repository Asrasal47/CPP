/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:08:03 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 00:55:32 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nam) : name(nam)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& we)
{
	this->w = &we;
}
