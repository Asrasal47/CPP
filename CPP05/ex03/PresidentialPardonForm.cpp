/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:34:31 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 22:09:28 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon", false, 25, 5)
{
	_target = "default";
	std::cout << "PresidentialForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("Presidential Pardon", false, 25, 5)
{
	_target = target;
	std::cout << "PresidentialForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy)
: AForm(copy)
{
	_target = copy.getTarget();
	std::cout << "PresidentialForm copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm& copy)
{
	std::cout << "PresidentialForm copy assign constructor called" << std::endl;
	AForm::operator=(copy);
	_target = copy.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialForm destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}