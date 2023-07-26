/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:42:05 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 21:53:17 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_sGrade;
	const unsigned int	_eGrade;

public:
	Form();
	Form(const std::string name);
	Form(const std::string name, bool status, const unsigned int signGrade, const unsigned int execGrade);
	Form(Form &form);
	Form	&operator=(Form &form);
	~Form();

	const std::string	getName(void) const;
	bool				getStatus(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getExecGrade(void) const;
	void				beSigned(Bureaucrat const &bureaucrat);

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

};

std::ostream	&operator<<(std::ostream &stream, Form &form);

#endif