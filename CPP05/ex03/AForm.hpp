/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:42:05 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 22:12:57 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_sGrade;
	const unsigned int	_eGrade;

public:
	AForm();
	AForm(const std::string name);
	AForm(const std::string name, bool status, const unsigned int signGrade, const unsigned int execGrade);
	AForm(AForm &form);
	AForm	&operator=(AForm &form);
	virtual ~AForm();

	const std::string	getName(void) const;
	bool				getStatus(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getExecGrade(void) const;
	void				beSigned(Bureaucrat const &bureaucrat);
	virtual void		action(void) const = 0;
	void				execute(Bureaucrat const &bureaucrat) const;

	class	GradeTooLowException: public std::exception
	{
		public:
		const char* what() const throw();
	};

	class	GradeTooHighException: public std::exception
	{
		public:
		const char* what() const throw();
	};
	class	FormNotSigned: public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, AForm &form);

#endif