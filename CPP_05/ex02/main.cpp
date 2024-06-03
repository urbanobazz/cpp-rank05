/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:17:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 19:47:48 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "------------------------------ 1st test ------------------------" << std::endl;
	try {
		Bureaucrat alice("Alice", 30);
		Bureaucrat bob("Bob", 70);
		RobotomyRequestForm form("Alice");

		alice.signForm(form);
		alice.executeForm(form);

		bob.signForm(form);
		bob.executeForm(form); // should throw exception grade too low
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	}
	std::cout << "------------------------------ 2nd test ------------------------" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 1);
		PresidentialPardonForm form("Alice");
		PresidentialPardonForm form2("Bob");

		alice.signForm(form);
		alice.executeForm(form);

		bob.executeForm(form2); // should throw exception form not signed
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
	std::cout << "------------------------------ 3rd test ------------------------" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 50);
		ShrubberyCreationForm form("Charlie");

		charlie.signForm(form);
		charlie.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
	return 0;
}
