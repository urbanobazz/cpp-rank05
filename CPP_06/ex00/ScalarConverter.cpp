/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:15:30 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 13:16:03 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {*this = other;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(std::string const &input)
{
	std::cout << "char: ";
	try {
		std::istringstream iss(input);
		int temp;
		iss >> temp;
		char c = static_cast<char>(temp);
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try {
		std::istringstream iss(input);
		int i;
		iss >> i;
		std::cout << i << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try {
		std::istringstream iss(input);
		float f;
		iss >> f;
		std::cout << f << "f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try {
		std::istringstream iss(input);
		double d;
		iss >> d;
		std::cout << d << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}
