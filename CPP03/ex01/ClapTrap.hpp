/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:48:36 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 20:46:52 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
protected:
		std::string		_name;
		unsigned int	_hitpoints;
		int	unsigned	_energypoints;
		int	unsigned	_attackdamage;

public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& claptrap);
		ClapTrap& operator=(ClapTrap& claptrap);
		virtual ~ClapTrap();

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void);
		int			getHit(void);
		int			getEnergy(void);
		int			getDamage(void);
		void		setName(std::string name);
		void		setHit(int points);
		void		setEnergy(int points);
		void		setDamage(int points);
};

std::ostream& operator<<(std::ostream& stream, ClapTrap& trap);

#endif