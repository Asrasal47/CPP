/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:44:33 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 22:39:58 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP
#include <iostream>
#include <sstream>
#include <stack>
#include <exception>

class RPN
{
private:
	std::string	expression_;
public:
	RPN(std::string exp = "");//default
	RPN(RPN const & copy);
	RPN& operator=(const RPN& copy);
	~RPN();

	int	process(const std::string& expression_);
};

#endif