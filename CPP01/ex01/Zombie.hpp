/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:47:20 by arasal            #+#    #+#             */
/*   Updated: 2023/03/29 21:56:24 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <new>

class Zombie
{
private:
		std::string	name;

public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	set_name(std::string _name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif