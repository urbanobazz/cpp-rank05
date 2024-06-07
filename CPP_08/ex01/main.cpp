/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:45:51 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 19:50:35 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "====================== Subject's test =====================" << std::endl;
	Span	sp(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "=========================== My test ========================" << std::endl;
	std::cout << "---------- 10k test ------------" << std::endl;
	try {
		Span	mySpan(10000);
		std::vector<int>	numbers(10000);
		for (std::vector<int>::size_type i = 0; i < numbers.size(); ++i)
			numbers[i] = i;
		mySpan.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------- 100k test ------------" << std::endl;
	try {
		Span	mySpan(100000);
		std::vector<int>	numbers(100000);
		for (std::vector<int>::size_type i = 0; i < numbers.size(); ++i)
			numbers[i] = i;
		mySpan.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------- 1M test ------------" << std::endl;
	try {
		Span	mySpan(1000000);
		std::vector<int>	numbers(1000000);
		for (std::vector<int>::size_type i = 0; i < numbers.size(); ++i)
			numbers[i] = i;
		mySpan.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "===================== Exceptions test ======================" << std::endl;
	std::cout << "---------- index out of bounds ------------" << std::endl;
	try {
		Span	mySpan(5);
		mySpan.addNumber(5);
		mySpan.addNumber(3);
		mySpan.addNumber(17);
		mySpan.addNumber(9);
		mySpan.addNumber(11);
		mySpan.addNumber(11); // one too much, should throw excepton
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------- not enough numbers stored ------------" << std::endl;
	try {
		Span	mySpan(5);
		mySpan.addNumber(5);
		std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=============================================================" << std::endl;
	return (0);
}
