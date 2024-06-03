/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:17:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 20:29:56 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "------------------------------ 1st test ------------------------" << std::endl;
	try {
		Intern	someRandomIntern;
		AForm*	rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Dummy");

		Bureaucrat	theBoss("The Boss", 1);

		theBoss.signForm(*rrf);
		theBoss.executeForm(*rrf);

		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	}
	std::cout << "------------------------------ 2nd test ------------------------" << std::endl;
	try {
		Intern	Intern1;
		AForm*	form;
		form = Intern1.makeForm("presidential pardon", "Dummy");

		Bureaucrat	theBoss("The Boss", 1);

		theBoss.signForm(*form);
		theBoss.executeForm(*form);

		delete form;
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
		Intern	Intern1;
		AForm*	form;
		form = Intern1.makeForm("shrubbery creation", "Dummy");

		Bureaucrat	theBoss("The Boss", 1);

		theBoss.signForm(*form);
		theBoss.executeForm(*form);

		delete form;
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
