/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:21:35 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 03:31:59 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif