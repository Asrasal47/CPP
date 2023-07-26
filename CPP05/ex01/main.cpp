/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:26:15 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 00:41:49 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat*	b = new Bureaucrat("john", 15);
		Form* form = new Form("testing", false, 15, 150);

		std::cout << std::endl;
		std::cout << *b << std::endl;
		std::cout << *form << std::endl;
		form->beSigned(*b);
		std::cout << *form << std::endl;
		b->decrement();
		b->signForm(*form);
		std::cout << std::endl;

		delete(b);
		delete(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}