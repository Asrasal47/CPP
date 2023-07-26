/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:24:39 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 22:14:19 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat()
: _name("Default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
: _name(name)
{
	std::cout << "Bureaucrat parameter constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat)
: _name(bureaucrat._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (bureaucrat._grade > 150)
		throw GradeTooLowException();
	if (bureaucrat._grade < 1)
		throw GradeTooHighException();
	_grade = bureaucrat._grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat copy assign constructor called" << std::endl;
	if (bureaucrat._grade > 150)
		throw GradeTooLowException();
	if (bureaucrat._grade < 1)
		throw GradeTooHighException();
	_grade = bureaucrat._grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void)	const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade(void)	const
{
	return _grade;
}

void	Bureaucrat::increment(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrement(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return stream;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

void	Bureaucrat::signForm(AForm &form) const
{
	if (_grade <= form.getSignGrade())
		form.beSigned(*this);
	else
		std::cout << _name << " could not sign " << form.getName() << " because the grade is too low: " << _grade << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() <<std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}