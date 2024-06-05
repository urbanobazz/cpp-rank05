/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:15:30 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 18:59:47 by ubazzane         ###   ########.fr       */
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
	int num = std::atoi(input.c_str());
	// Char
	std::cout << "Char: ";
	if (input.size() == 1 && input[0] != '0')
		num = static_cast<int>(input[0]);
	if (num == 0 && !(input.size() == 1 && input[0] == '0'))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(num))
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "non displayable" << std::endl;

	//Int
	std::cout << "Int: ";
	if (num == 0 && !(input.size() == 1 && input[0] == '0'))
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << std::endl;

	//Float
	std::cout << "Float: ";
	char *end;
	float f = std::strtof(input.c_str(), &end);
	if (input.size() == 1 && input[0] != '0')
	{
		f = static_cast<float>(input[0]);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else if (end == input.c_str() || (f == 0.0f && input != "0" && input != "0.0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	//Double
	std::cout << "Double: ";
	double d = strtod(input.c_str(), &end);
	if (input.size() == 1 && input[0] != '0')
	{
		d = static_cast<double>(input[0]);
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (end == input.c_str() || (d == 0.0 && input != "0" && input != "0.0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}
