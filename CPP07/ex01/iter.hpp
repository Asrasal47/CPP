/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:02:37 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 17:57:25 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define ITER_HPP

#include<iostream>

template <typename T>
void	iter(T* ptr, size_t length, void (*f)(T&))
{
	for(size_t i = 0; i < length; i++)
		f(ptr[i]);
}

template <typename T>
void	print(T& t)
{
	std::cout << t << " ";
}

#endif
