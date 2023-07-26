/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:16:53 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 17:04:50 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << std::endl;
		Bureaucrat*	john = new Bureaucrat("john", 2);
		std::cout << std::endl;
		Bureaucrat* tam = new Bureaucrat("tam", 42);
		std::cout << std::endl;
		AForm* form1 = new ShrubberyCreationForm("form1");
		std::cout << std::endl;
		AForm* form2 = new RobotomyRequestForm("form2");
		std::cout << std::endl;
		AForm* form3 = new PresidentialPardonForm("form3");

		std::cout << "------------------------------------------------" << std::endl;
		std::cout << *john << std::endl;
		std::cout << *tam << std::endl;
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		std::cout << "------------------------------------------------" << std::endl;
		form1->beSigned(*john);
		form2->beSigned(*tam);
		form3->beSigned(*john);

		std::cout << "------------------------------------------------" << std::endl;
		form1->execute(*john);
		std::cout << std::endl;
		tam->executeForm(*form2);
		std::cout << std::endl;
		form3->execute(*john);

		std::cout << "------------------------------------------------" << std::endl;
		delete(john);
		std::cout << std::endl;
		delete(tam);
		std::cout << std::endl;
		delete(form1);
		std::cout << std::endl;
		delete(form2);
		std::cout << std::endl;
		delete(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
