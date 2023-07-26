/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:12:09 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 21:15:33 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& t1, T& t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template <typename T>
T const &	max(T const & t1, T const & t2)
{
	return (t1 > t2 ? t1 : t2);
}

template <typename T>
T const &	min(T const & t1, T const & t2)
{
	return (t1 < t2 ? t1 : t2);
}

#endif