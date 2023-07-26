/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:05:59 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 03:05:20 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class	Array
{
	private:

		T*				_array;
		unsigned int 	_size;
	
	public:
		Array()
		{
			std::cout << "Array default costructor called" << std::endl;
			_array = new T[0]();
			_size = 0;
		}
		
		Array(unsigned int n)
		{
			std::cout << "Array costructor array(int) called" << std::endl;
			_array = new T[n]();
			_size = n;
		}
		
		Array(Array& copy)
		{
			std::cout << "Array copy costructor called" << std::endl;
			_size = copy.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			_array[i] = T(copy.getArray()[i]);
		}
		
		Array& operator=(Array& copy)
		{
			std::cout << "Array copy assign operator called" << std::endl;
			delete[] _array;
			_size = copy.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = T(copy.getArray()[i]);
			return (*this);
		}
		
		~Array()
		{
			std::cout << "Array destructor called" << std::endl;
			delete[] _array;
		}
		
		T& operator[](unsigned int index) const
		{
			if (index < _size)
			return _array[index];
			throw std::exception();
		}
		
		unsigned int size(void) const
		{
			return _size;
		}
		
		T*			getArray(void) const
		{
			return _array;
		}
};
#endif