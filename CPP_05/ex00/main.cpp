/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:17:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 17:31:15 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "------------------------------ 1st test ------------------------" << std::endl;
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.increment();
		std::cout << bob << std::endl;

		bob.increment(); // This should throw an exception
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "------------------------------ 2nd test ------------------------" << std::endl;
	try {
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;

		alice.decrement();
		std::cout << alice << std::endl;

		alice.decrement(); // This should throw an exception
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "------------------------------ 3rd test ------------------------" << std::endl;
	try {
		Bureaucrat Jack("Jack", 200);
		std::cout << Jack << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
