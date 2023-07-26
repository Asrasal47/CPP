/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:44:30 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 22:10:16 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation", false, 145, 137)
{
	_target = "default";
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("Shrubbery Creation", false, 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy)
: AForm(copy)
{
	_target = copy.getTarget();
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy)
{
	std::cout << "ShrubberyCreationForm copy assign constructor called" << std::endl;
	AForm::operator=(copy);
	_target = copy.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void	ShrubberyCreationForm::action(void) const
{
	std::fstream file((_target + "_shrubbery").c_str(), std::ios::out);
	if (file.bad())
	{
		std::cout << "Error: failed to create " << _target + "_shrubbery" << std::endl;
		return ;
	}
	//should check for every writing put it's not the point of the exercise
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&\\%\\%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@8\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&\\%\\%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	file.close();
}