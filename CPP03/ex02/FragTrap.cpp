/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:15:55 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 20:17:19 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap& fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}
FragTrap& FragTrap::operator=(FragTrap& fragtrap)
{
	ClapTrap::operator=(fragtrap);
	std::cout << "FragTrap copy Assign constructor called for " << _name << std::endl;
	return (fragtrap);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_hitpoints > 0 && _energypoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage." << std::endl;
		_energypoints--;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << _name << ": L E T    U S    H I G H    F I V E    G U Y S!!!" << std::endl;
}