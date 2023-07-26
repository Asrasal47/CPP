/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 03:21:16 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 03:24:44 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <list>

template<typename T>
class MutantStack: public std::stack<T>
{

public:
	MutantStack(){}
	MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy){}
	MutantStack&	operator=(const MutantStack<T>& copy)
	{ 
		std::stack<T>::operator=(copy); return *this;
	}
	~MutantStack(){}
	typedef typename std::stack<T>::container_type::iterator    iterator;
	iterator	begin(void)
	{
		return this->c.begin();
	}
	iterator	end(void)
	{
		return this->c.end();
	}
};

#endif