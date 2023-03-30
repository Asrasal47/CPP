/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:05:15 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 18:25:00 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
private:
		std::string	_ideas[100];
public:
		Brain();
		Brain(Brain& brain);
		Brain& operator=(Brain& brain);
		~Brain();

		std::string		getIdea(int index) const;
		void			setIdea(int index, std::string idea);
};

#endif