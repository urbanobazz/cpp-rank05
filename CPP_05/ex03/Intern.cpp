/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:53:24 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/04 12:28:59 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	AForm *(Intern::*membFunction[3])(std::string) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*membFunction[i])(target);
		}
	}
	throw FormNotFoundException();
}

AForm *Intern::createShrubberyCreationForm(std::string target) const {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target) const {
	return new PresidentialPardonForm(target);
}
const char *Intern::FormNotFoundException::what() const throw() {
	return ("Form not found!");
}
