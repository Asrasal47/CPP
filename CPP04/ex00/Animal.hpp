/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:03:18 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 16:09:00 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
protected:
		std::string	_type;
public:
		Animal();
		Animal(Animal& animal);
		Animal& operator=(Animal& animal);
		virtual ~Animal();

		virtual void		makeSound() const;
		std::string			getType() const;
		void				setType(std::string typ);
};

#endif