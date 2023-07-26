/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:43:51 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 22:46:07 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string exp)
: expression_(exp)
{
	
}

RPN::RPN(const RPN& copy)
: expression_(copy.expression_)
{
	
}

RPN& RPN::operator=(const RPN& copy)
{
	expression_=copy.expression_;
	return (*this);
}

RPN::~RPN()
{
	
}

int RPN::process(const std::string& input)
{
	std::stack<int> stack;
	std::istringstream iss(input);
	std::string token;
	while (iss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (stack.size() < 2) {
			    throw std::runtime_error("Invalid expression");
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			if (token == "+") stack.push(a + b);
			else if (token == "-") stack.push(a - b);
			else if (token == "*") stack.push(a * b);
			else if (token == "/") {
			    if (b == 0) throw std::runtime_error("Division by zero");
			    stack.push(a / b);
			}
		} else {
			int num;
			std::istringstream(token) >> num;
			if (num >= 10) throw std::runtime_error("Number greater than or equal to 10");
			stack.push(num);
		}
	}
	if (stack.size() != 1) throw std::runtime_error("Invalid expression");
	return stack.top();
}
