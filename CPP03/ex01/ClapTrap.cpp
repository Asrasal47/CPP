/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:48:10 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 21:01:27 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:
_name(""),
_hitpoints(10),
_energypoints(10),
_attackdamage(0)
{
	std::cout << "Default ClapTrap Constructor called" << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:
_name(name),
_hitpoints(10),
_energypoints(10),
_attackdamage(0)
{
	std::cout << "Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& claptrap)
:
_name(claptrap.getName()),
_hitpoints(claptrap.getHit()),
_energypoints(claptrap.getEnergy()),
_attackdamage(claptrap.getDamage())
{
	std::cout << "Copy Constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& claptrap)
{
	std::cout << "Copy Assign constructor." << std::endl;
	_name = claptrap.getName();
	_hitpoints = claptrap.getHit();
	_energypoints = claptrap.getEnergy();
	_attackdamage = claptrap.getDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energypoints == 0 || _hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Cannot attack" << std::endl;
		return ;
	}
	if (_hitpoints > 0 && _energypoints > 0)
	{
		std::cout << "Claptrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackdamage << " points of damage!" << std::endl;
		_energypoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	dam;

	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
		return ;
	}
	if (_hitpoints > amount)
	{
		dam = amount;
		_hitpoints -= amount;
	}
	else
	{
		dam = _hitpoints;
		std::cout << "ClapTrap " << _name << " takes " << dam << " points of damage." << std::endl;
		_hitpoints = 0;
		std::cout << "Critical hit! ClapTrap " << _name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << dam << " points of damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energypoints == 0 || _hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Cannot be repaired." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is repaired with " << amount << " points!" << std::endl;
	_hitpoints += amount;
	_energypoints -= 1;
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

int	ClapTrap::getHit(void)
{
	return (_hitpoints);
}

int	ClapTrap::getEnergy(void)
{
	return (_energypoints);
}

int	ClapTrap::getDamage(void)
{
	return (_attackdamage);	
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHit(int points)
{
	_hitpoints = points;
}

void	ClapTrap::setEnergy(int points)
{
	_energypoints = points;
}

void	ClapTrap::setDamage(int points)
{
	_attackdamage = points;
}

std::ostream& operator<< (std::ostream& stream, ClapTrap& claptrap)
{
	stream << "Name: " << claptrap.getName() << ", Hit points: " << claptrap.getHit() << ", Energy points: " << claptrap.getEnergy() << ", Attack damage: " << claptrap.getDamage();
	return (stream);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}