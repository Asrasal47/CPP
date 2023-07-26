/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:16:39 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 17:21:34 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern &copy)
{
	*this = copy;
	std::cout << "Intern copy constructor called." << std::endl;
}

Intern&	Intern::operator=(Intern &copy)
{
	(void)copy;
	std::cout << "Intern copy assign operator called." << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm* form = NULL;
	std::string formNames[3] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};
	int i;
	for (i = 0; i < 3; i++)
		if (formNames[i] == name)
			break;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Invalid form name passed!" << std::endl;
			return (form);
	}
	std::cout << "Intern creates " << name << std::endl;
	return (form);
}
