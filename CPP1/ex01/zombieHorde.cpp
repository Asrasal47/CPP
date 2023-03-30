/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:50:25 by arasal            #+#    #+#             */
/*   Updated: 2023/03/29 23:18:57 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* z = new Zombie[10];
	int		i;
	
	i = 0;
	while (i < N)
	{
		z[i].set_name(name);
		i++;
	}
	return (z);
}
