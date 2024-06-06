/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:01:49 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/06 16:14:19 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> intArray(5);
	Array<std::string> stringArray(3);
	Array<float> floatArray(8);

	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i + 1;
	for (unsigned int i = 0; i < stringArray.size(); i++)
		stringArray[i] = "Hello, World!";
	for (unsigned int i = 0; i < floatArray.size(); i++)
		floatArray[i] = i + 0.5;

	std::cout << "======================== IntArray ============================ " << std::endl;
	std::cout << "Array: ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "======================== StringArray ========================= " << std::endl;
	std::cout << "Array: ";
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;

	std::cout << "======================== FloatArray ========================== " << std::endl;
	std::cout << "Array: ";
	for (unsigned int i = 0; i < floatArray.size(); i++)
		std::cout << floatArray[i] << " ";
	std::cout << std::endl;

	std::cout << "======================== Exception =========================== " << std::endl;
	std::cout << "Trying to access out of bound index of intArray: " << std::endl;
	try
	{
		std::cout << intArray[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "===================== Empty array test =======================" << std::endl;
	Array<int> emptyArray;

	std::cout << "Array size: " << emptyArray.size() << std::endl;
	emptyArray = intArray;
	std::cout << "Array size after assignment: " << emptyArray.size() << std::endl;
	std::cout << "Array: ";
	for (unsigned int i = 0; i < emptyArray.size(); i++)
		std::cout << emptyArray[i] << " ";
	std::cout << std::endl;

	std::cout << "==============================================================" << std::endl;


	return (0);
}
