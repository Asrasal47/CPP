/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:40:26 by arasal            #+#    #+#             */
/*   Updated: 2023/03/28 19:01:14 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits.h>

class Contact
{
private:
		std::string	_f_name;
		std::string	_l_name;
		std::string	_n_name;
		std::string	_p_number;
		std::string	_darkest_secret;

public:
		Contact();
		~Contact();
		
		void	set_f_name(const std::string fname);
		void	set_l_name(const std::string lname);
		void	set_n_name(const std::string nname);
		void	set_p_number(const std::string num);
		void	set_darkest_secret(const std::string d_secret);

		std::string	get_f_name() const;
		std::string	get_l_name() const;
		std::string	get_n_name() const;
		std::string	get_p_number() const;
		std::string	get_darkest_secret() const;
};

#endif