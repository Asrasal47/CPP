/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:03:18 by arasal            #+#    #+#             */
/*   Updated: 2023/03/31 22:17:54 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
		std::string	_type;
public:
		WrongAnimal();
		WrongAnimal(WrongAnimal& animal);
		WrongAnimal& operator=(WrongAnimal& animal);
		virtual ~WrongAnimal();

		void		makeSound() const;
		std::string			getType() const;
		void				setType(std::string typ);
};

#endif