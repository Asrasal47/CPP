/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:10:52 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 00:55:06 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
private:
		std::string name;
		Weapon 		*w;

public:
		HumanB(std::string nam);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon& we);
};

#endif