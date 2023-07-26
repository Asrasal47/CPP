/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:38:26 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 22:10:42 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <cstdlib>
# include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robot Request", false, 72, 45)
{
	_target = "default";
	std::cout << "RobotomyForm default constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robot Request", false, 72, 45)
{
	_target = target;
	std::cout << "RobotomyForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy)
: AForm(copy)
{
	_target = copy.getTarget();
	std::cout << "RobotomyForm copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm& copy)
{
	std::cout << "RobotomyForm copy assign constructor called" << std::endl;
	AForm::operator=(copy);
	_target = copy.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyForm destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget()  const
{
	return _target;
}

void	RobotomyRequestForm::action(void) const
{
	struct timeval  t;
	gettimeofday(&t, NULL);
	srand(t.tv_usec);
	std::cout << "DDDDRRRRRRIIIIILLLLL!!!!" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomizing " << _target << " has failed" << std::endl;
}