/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:26:15 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 21:48:19 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	*b = new Bureaucrat("Shibam", 2);
		std::cout << *b << std::endl;
		b->decrement();
		std::cout << *b << std::endl;
		b->increment();
		std::cout << *b << std::endl;
		b->increment();
		std::cout << *b << std::endl;
		b->increment();
		std::cout << *b << std::endl;
		delete (b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	*c = new Bureaucrat("Elvis", 150);
		delete (c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}