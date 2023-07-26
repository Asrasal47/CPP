/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:28:16 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 20:53:50 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
	std::cout << "Default ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}
ScavTrap& ScavTrap::operator=(ScavTrap& scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "ScavTrap copy Assign constructor called for " << _name << std::endl;
	return (scavtrap);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitpoints > 0 && _energypoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage." << std::endl;
		_energypoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << _name << ": Y O U    S H A L L    N O T    P A S S!!!" << std::endl;
}