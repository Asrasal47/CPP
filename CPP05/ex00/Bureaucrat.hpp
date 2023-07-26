/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:55 by arasal            #+#    #+#             */
/*   Updated: 2023/06/29 21:42:54 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string str, unsigned int grade);
		Bureaucrat(Bureaucrat &bureaucrat);
		Bureaucrat &operator=(Bureaucrat &bureaucrat);
		~Bureaucrat();

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				increment(void);
		void				decrement(void);

		class	GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class	GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat &bureaucrat);
#endif