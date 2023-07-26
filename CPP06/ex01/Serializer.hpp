/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:01:00 by arasal            #+#    #+#             */
/*   Updated: 2023/06/28 19:03:27 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <sstream>
# include <string>

typedef	struct s_Data
{
	std::string	string_data;
	int			int_data;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(Serializer& copy);
	Serializer&	operator=(Serializer& copy);
	~Serializer();
public:
	static	uintptr_t	serialize(Data* ptr);
	static	Data*		deserialize(uintptr_t raw);
};

std::ostream&	operator<<(std::ostream& stream, Data& data);

#endif