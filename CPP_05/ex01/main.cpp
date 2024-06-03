/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:17:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 17:18:50 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "------------------------------ 1st test ------------------------" << std::endl;
	try {
		Bureaucrat alice("Alice", 50);
		std::cout << alice << std::endl;
		Form taxForm("Tax Form", 75, 50);
		std::cout << taxForm << std::endl;
		Form visaForm("Visa Form", 20, 25);
		std::cout << visaForm << std::endl;

		alice.signForm(taxForm);
		alice.signForm(visaForm); // should throw error
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------ 2nd test ------------------------" << std::endl;
	try {
		Bureaucrat bob("Bob", 1); // highest grade
		std::cout << bob << std::endl;
		Form taxForm("Tax Form", 75, 50);
		std::cout << taxForm << std::endl; // should show as not signed.

		bob.signForm(taxForm);
		std::cout << taxForm << std::endl; // must show as signed.
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------ 3rd test ------------------------" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 150); // lowest grade

		charlie.decrement(); // Should throw error
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------ 4th test ------------------------" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1); // highest grade

		charlie.increment(); // Should throw error
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
