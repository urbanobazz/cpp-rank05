/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:33 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/06 15:36:59 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "print.hpp"
#include <string>

int main(void)
{
	int		int_array[5] = {1, 2, 3, 4, 5};
	float	float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string string_array[5] = {"Hello", "World", "42", "Berlin", "C++"};

	std::cout << "Int array:" << std::endl;
	iter(int_array, 5, print);
	std::cout << std::endl;

	std::cout << "Float array:" << std::endl;
	iter(float_array, 5, print);
	std::cout << std::endl;

	std::cout << "Char array:" << std::endl;
	iter(char_array, 5, print);
	std::cout << std::endl;

	std::cout << "String array:" << std::endl;
	iter(string_array, 5, print);
	std::cout << std::endl;

	return (0);
}
