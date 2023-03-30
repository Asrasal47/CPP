/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:52 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 17:25:26 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

class Phonebook
{
private:
		Contact	_contact[8];
		int	_count;
		int	_index;

public:
		Phonebook();
		~Phonebook();

		void	set_Contact(Contact contact);
		Contact get_Contact(int index) const;
		int		get_Count(void);
};

#endif