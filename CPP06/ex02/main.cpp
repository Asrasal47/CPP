/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:13:07 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 14:36:53 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"
#include <iostream>
#include <sys/time.h>


Base* generate(void)
{
	struct timeval  t;
	gettimeofday(&t, NULL);
	srand(t.tv_usec);
	int	choice = rand() % 3;
	Base* base;
	switch (choice)
	{
	case 0:
		std::cout << "type A generated" << std::endl;
		base = new A;
		break;
	case 1:
		std::cout << "type B generated" << std::endl;
		base = new B;
		break;
	case 2:
		std::cout << "type C generated" << std::endl;
		base = new C;
		break;
	}
	return base;
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "1-type A detected" << std::endl;
	if (b)
		std::cout << "1-type B detected" << std::endl;
	if (c)
		std::cout << "1-type C detected" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "2-type A detected" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "it wasn't a A type" << '\n';
	}
	try
	{
		B a = dynamic_cast<B&>(p);
		(void)a;
		std::cout << "2-type B detected" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "it wasn't a B type" << '\n';
	}
	try
	{
		C a = dynamic_cast<C&>(p);
		(void)a;
		std::cout << "2-type C detected" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "it wasn't a C type" << '\n';
	}
}

int main(void)
{
	Base *b = generate();
	identify(b);
	identify(*b);
	delete (b);
	return 0;
}
