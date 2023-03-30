/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:03:19 by arasal            #+#    #+#             */
/*   Updated: 2023/03/30 03:16:29 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<fstream>
#include<cstring>

int	main(int argc, char **argv)
{
	std::string		infile, str1, str2, gnl, line, outfile;
	std::ifstream	in;
	std::ofstream	out;
	int				i;

	if (argc != 4)
	{
		std::cout << "argc: error !: invalid input" << std::endl;
		std::cout << "usage: ./sed <filename1> <string to be replaced> <string to replace with>" << std::endl;
		return (1);
	}
	infile = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	i = 0;
	if (str1.empty())
	{
		std::cout << "String to b e replaced cannot be empty!" << std::endl;
		return (1);
	}
	outfile = infile;
	outfile = outfile.append(".replace");
	in.open(infile);
	out.open(outfile);
	while (!in.eof())
	{
		i = 0;
		getline(in, gnl);
		while (i != -1)
		{
			i = gnl.find(str1);
			if (i == -1)
				break ;
			else
			{
				line = gnl.substr(0, i) + str2 + gnl.substr(i + str1.length());
				gnl = line;
			}
		}
		out << gnl << std::endl;
	}
	in.close();
	out.close();
	return (0);
}