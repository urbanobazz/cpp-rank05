/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:18:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 17:25:21 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(0) {
		if (grade < 1 )
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
			_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::string Bureaucrat::getName(void) const {
	return (_name);
}

unsigned int Bureaucrat::getGrade(void) const {
	return (_grade);
}

void Bureaucrat::increment(void) {
	if (_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
	return;
}

void Bureaucrat::decrement(void) {
		if (_grade >= 150)
			throw GradeTooLowException();
	this->_grade++;
	return;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other) {
	stream << other.getName() << ", Bureaucrat grade: " << other.getGrade() << std::endl;
	return (stream);
}

void Bureaucrat::signForm(Form &other) {

	if (_grade > other.getGradeToSign())
		std::cout << _name << " couldn't sign " << other.getName() << " because the grade was too low." << std::endl;
	else
	{
		other.beSigned(*this);
		std::cout << _name << " signed " << other.getName() << "." << std::endl;
	}

}
