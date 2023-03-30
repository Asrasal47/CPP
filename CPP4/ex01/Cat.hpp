/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:33:42 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 18:32:52 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
		Brain	*_brain;
public:
		Cat();
		Cat(Cat& cat);
		Cat& operator=(Cat& cat);
		~Cat();

		void		makeSound() const;
		Brain*		getBrain(void) const;
};

#endif