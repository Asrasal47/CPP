/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:59:53 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 22:00:06 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

Form::Form()
: _name("default"), _signed(false), _sGrade(1), _eGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name)
: _name(name), _signed(false), _sGrade(1), _eGrade(1)
{
	std::cout << "Form param constructor called" << std::endl;
}

Form::Form(const std::string name, bool status, unsigned int sGrade, unsigned int eGrade)
: _name(name), _signed(status), _sGrade(sGrade), _eGrade(eGrade)
{
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form &form)
: _name(form._name), _signed(form._signed), _sGrade(form._sGrade), _eGrade(form._eGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (form._sGrade < 1 || form._eGrade < 1)
		throw GradeTooHighException();
	if (form._sGrade > 150 || form._eGrade > 150)
		throw GradeTooLowException();
	_signed = form._signed;
}

Form	&Form::operator=(Form &form)
{
	std::cout << "Form copy assign constructor called" << std::endl;
	if (form._sGrade < 1 || form._eGrade < 1)
		throw GradeTooHighException();
	if (form._sGrade > 150 || form._eGrade > 150)
		throw GradeTooLowException();
	_signed = form._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string	Form::getName(void) const
{
	return _name;
}

bool	Form::getStatus(void) const
{
	return _signed;
}

unsigned int	Form::getSignGrade(void) const
{
	return _sGrade;
}

unsigned int	Form::getExecGrade(void) const
{
	return _eGrade;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	unsigned int	grade = bureaucrat.getGrade();
	if (_sGrade >= grade)
	{
		_signed = true;
		std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &stream, Form &form)
{
	stream << form.getName() << ", signed: " << form.getStatus() << ", signing Grade: " << form.getSignGrade() << ", execution Grade: " << form.getExecGrade() << ".";
	return stream;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}