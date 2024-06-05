/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:57:47 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 18:39:44 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *ptr = new Data;

	ptr->x = 2;
	ptr->y = 5;

	std::cout << "Adress of ptr: "<< ptr << std::endl;
	uintptr_t a = Serializer::serialize(ptr);
	std::cout << "Value of a: " << a << std::endl;
	Data *b = Serializer::deserialize(a);
	std::cout << "Value of b: " << b << std::endl;

	std::cout << "b->x = " << b->x << std::endl;
	std::cout << "b->y = " << b->y << std::endl;

	delete ptr;
}
