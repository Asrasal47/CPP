/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:59:53 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 14:56:59 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"

AForm::AForm()
: _name("default"), _signed(false), _sGrade(1), _eGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name)
: _name(name), _signed(false), _sGrade(1), _eGrade(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool status, unsigned int sGrade, unsigned int eGrade)
: _name(name), _signed(status), _sGrade(sGrade), _eGrade(eGrade)
{
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm &form)
: _name(form._name), _signed(form._signed), _sGrade(form._sGrade), _eGrade(form._eGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	if (form._sGrade < 1 || form._eGrade < 1)
		throw GradeTooHighException();
	if (form._sGrade > 150 || form._eGrade > 150)
		throw GradeTooLowException();
	_signed = form._signed;
}

AForm	&AForm::operator=(AForm &form)
{
	std::cout << "AForm copy assign constructor called" << std::endl;
	if (form._sGrade < 1 || form._eGrade < 1)
		throw GradeTooHighException();
	if (form._sGrade > 150 || form._eGrade > 150)
		throw GradeTooLowException();
	_signed = form._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string	AForm::getName(void) const
{
	return _name;
}

bool	AForm::getStatus(void) const
{
	return _signed;
}

unsigned int	AForm::getSignGrade(void) const
{
	return _sGrade;
}

unsigned int	AForm::getExecGrade(void) const
{
	return _eGrade;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
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

void	AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (_signed == false)
		throw FormNotSigned();
	if (bureaucrat.getGrade() > _eGrade)
		throw GradeTooLowException();
	action();
}

std::ostream	&operator<<(std::ostream &stream, AForm &form)
{
	stream << form.getName() << ", signed: " << form.getStatus() << ", signing Grade: " << form.getSignGrade() << ", execution Grade: " << form.getExecGrade() << ".";
	return stream;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return "Form Not Signed";
}

