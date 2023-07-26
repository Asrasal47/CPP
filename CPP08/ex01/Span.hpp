/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:34:08 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 20:49:35 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <exception>
# include <string>
# include <algorithm>
# include <ostream>
# include <iostream>
# include <random>

class Span
{
private:
	const unsigned int		_size;
	std::vector<int>		_spans;
public:
	Span();
	Span(unsigned int size);
	Span(const Span& copy);
	Span&	operator=(Span& copy);
	~Span();

	void				addNumber(int num);
	int					shortestSpan(void) const;
	int					longestSpan(void) const;
	unsigned int		getSize(void) const;
	std::vector<int>	getSpans(void) const;
	template <typename Iterator>
	void				addNumbers(Iterator it1, Iterator it2)
	{
		unsigned int	left_space = _size - _spans.size();
		if (left_space < it2 - it1)
			throw NotEnoughSpaceLeftException();
		std::copy(it1, it2, back_inserter(_spans));
	}

	class	SpanFullException:public std::exception
	{
		const char* what() const throw();
	};

	class	NoSpanFoundException:public std::exception
	{
		const char* what() const throw();
	};

	class	NotEnoughSpaceLeftException:public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& out, Span& sp);

#endif