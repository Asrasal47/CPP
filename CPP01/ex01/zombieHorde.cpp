/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:50:25 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 15:42:46 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 0)
	{
		std::cout << "Invalid number" << std::endl;
		return (NULL);
	}
	Zombie* z = new Zombie[N];
	int		i;
	
	i = 0;
	while (i < N)
	{
		z[i].set_name(name);
		i++;
	}
	return (z);
}
