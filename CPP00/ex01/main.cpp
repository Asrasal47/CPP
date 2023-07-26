/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:13 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 17:37:02 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

void	display_single_contact(Phonebook *pb, int x)
{
	Contact ctct;

	ctct = pb->get_Contact(x);
	std::cout << "First Name : ";
	std::cout << ctct.get_f_name() << std::endl;
	std::cout << "Last Name : ";
	std::cout << ctct.get_l_name() << std::endl;
	std::cout << "Nick Name : ";
	std::cout << ctct.get_n_name() << std::endl;
	std::cout << "Phone number : ";
	std::cout << ctct.get_p_number() << std::endl;
	std::cout << "Darkest Secret : ";
	std::cout << ctct.get_darkest_secret() << std::endl;
}

int	atoi_str(std::string str)
{
	int	i;

	i = 0;
	if (!str.length())
		return (-1);
	if (str[i] == '+')
		i++;
	if (!str.length())
	{
		std::cout << "Invalid input";
		return (-1);
	}
	if (str[i] > '0' && str[i] <= '9')
		return (str[i] - '0');
	return (-1);
}

void	choose_contact(Phonebook *pb)
{
	std::string	str;
	int			i;

	while (1)
	{
		std::cout << "Please choose a contact by index to display" << std::endl;
		std::cout << "Or enter 'BACK' to go back" << std::endl;
		std::getline(std::cin, str);
		if (str == "BACK")
			break ;
		i = atoi_str(str);
		if (i > 0 && i <= pb->get_Count())
		{
			display_single_contact(pb, i - 1);
			return ;
		}
	}
}

void	display_contact(Phonebook *pb)
{
	Contact		ctct;
	int			count;
	int			j;
	std::string	get;

	count = pb->get_Count();
	j = 0;
	std::cout << std::endl << std::string(45,'+') << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << "First name";
	std::cout << "|" << std::setw(10) << std::right << "Last name";
	std::cout << "|" << std::setw(10) << std::right << "Nick name" << "|" << std::endl;
	std::cout << std::string(45,'-') << std::endl;
	while (j < count)
	{
		ctct = pb->get_Contact(j);
		std::cout << "|" << std::setw(10) << std::right << j + 1;
		get = ctct.get_f_name();
		if (get.length() > 10)
		{
			get.resize(9);
			get.append(1, '.');
		}
		std::cout << "|" << std::setw(10) << std::right << get;
		get.clear();
		get = ctct.get_l_name();
		if (get.length() > 10)
		{
			get.resize(9);
			get.append(1, '.');
		}
		std::cout << "|" << std::setw(10) << std::right << get;
		get.clear();
		get = ctct.get_n_name();
		if (get.length() > 10)
		{
			get.resize(9);
			get.append(1, '.');
		}
		std::cout << "|" << std::setw(10) << std::right << get << "|" << std::endl;
		get.clear();
		j++;
	}
	std::cout << std::endl << std::string(45,'+') << std::endl;
	choose_contact(pb);
}

void	add_contact(Phonebook *pb)
{
	Contact 	ctct;
	std::string	input;;

	std::cout << "Please enter the contact information: " << std::endl;
	std::cout << "Note: Fields cannot be left empty" << std::endl;
	while (!input.length())
	{
		std::cout << "First Name : ";
		std::getline(std::cin, input);
	}
	ctct.set_f_name(input);
	input.clear();
	while (!input.length())
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, input);
	}
	ctct.set_l_name(input);
	input.clear();
	while (!input.length())
	{
		std::cout << "Nick Name : ";
		std::getline(std::cin, input);
	}
	ctct.set_n_name(input);
	input.clear();
	while (!input.length())
	{
		std::cout << "Phone Number : ";
		std::getline(std::cin, input);
	}
	ctct.set_p_number(input);
	input.clear();
	while (!input.length())
	{
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, input);
	}
	ctct.set_darkest_secret(input);
	input.clear();
	pb->set_Contact(ctct);
}

int	main(void)
{
	Phonebook	pb;
	std::string	cmd;
	int			i;

	while (1)
	{
		std::cout << "Available commands:" << std::endl;
		std::cout << "1: ADD" << std::endl;
		std::cout << "2: SEARCH" << std::endl;
		std::cout << "3: EXIT" << std::endl;
		std::getline(std::cin, cmd);
		i = atoi_str(cmd);
		if (cmd == "ADD" || i == 1)
			add_contact(&pb);
		else if (cmd == "SEARCH" || i == 2)
			display_contact(&pb);
		else if (cmd == "EXIT" || i == 3)
			break ;
		else
		{
			std::cout << "what are you doing habibi ??" << std::endl;
			std::cout << "Enter the correct command!!" << std::endl;
		}
	}
	return (0);
}
