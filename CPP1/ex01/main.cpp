/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:07:28 by arasal            #+#    #+#             */
/*   Updated: 2023/03/29 22:25:11 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z;
	int		i;
	int		N;

	N = 10;
	i = 0;
	z = zombieHorde(N, "Robel");
	while (i < N)
	{
		(z + i)->announce();
		i++;
	}
	i = 0;
	delete[] z;
	system("leaks Zombie");
	return (0);
}