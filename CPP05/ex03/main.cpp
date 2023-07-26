/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:13:02 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 17:24:04 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Intern* newbie = new Intern();
	
		AForm* form = newbie->makeForm("Shrubbery Creation", "target");
		if (form)
		{
			std::cout << *form << std::endl;
			form->action();
			delete(form);
		}
		delete(newbie);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}