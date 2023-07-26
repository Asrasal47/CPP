/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:47:20 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 13:36:38 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

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

void	randomChump(std::string name);

Zombie*	newZombie(std::string name);

#endif