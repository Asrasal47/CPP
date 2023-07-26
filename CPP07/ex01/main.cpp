/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:03:02 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 17:59:15 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <string>

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, &print);
    std::cout << std::endl;

    float array2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(array2, 5, &print);
    std::cout << std::endl;

    std::string array3[5] = {"hi", "wassup", "fine", "good bye", "see you"};
    iter(array3, 5, &print);
    std::cout << std::endl;
    return 0;
}
