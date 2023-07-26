/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:47:55 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 13:53:13 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe("Joe");

	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << joe << std::endl;
	john.attack("Marge");
	john.attack("Bart");
	john.attack("Homer");
	std::cout << john << std::endl;
	john.takeDamage(5);
	std::cout << john << std::endl;
	jim.takeDamage(9);
	jim.takeDamage(10);
	std::cout << jim << std::endl;
	joe.beRepaired(10);
	joe.takeDamage(19);
	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << joe << std::endl;
	return (0);
}
