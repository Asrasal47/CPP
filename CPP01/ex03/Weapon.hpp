/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:57 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 14:04:54 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
		std::string type;
		
public:
		Weapon(std::string typ);
		Weapon();
		~Weapon();
		
		const std::string&	getType(void);
		void	setType(std::string typ);
};

#endif