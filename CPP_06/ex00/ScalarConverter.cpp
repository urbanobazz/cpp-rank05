/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:15:30 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 13:03:31 by ubazzane         ###   ########.fr       */
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
		char c = static_cast<char>(std::stoi(input));
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
		int i = std::stoi(input);
		std::cout << i << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try {
		float f = std::stof(input);
		std::cout << f << "f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try {
		double d = std::stod(input);
		std::cout << d << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}
