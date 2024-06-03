/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:42 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 17:26:15 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
_name("DEFAULT_NAME"),
_isSigned(false),
_gradeToSign(1),
_gradeToExecute(1) {return;}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) :
_name(name),
_isSigned(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute) {return;}

Form::Form(const Form &other) :
_name(other._name),
_isSigned(other._isSigned),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute) {return;}

Form::~Form(void) {return;}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

void Form::beSigned(const Bureaucrat &other) {
	if (other.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string Form::getName() const {return (_name);}

bool Form::getIsSigned() const  {return (_isSigned);}

unsigned int Form::getGradeToSign() const {return (_gradeToSign);}

unsigned int Form::getGradeToExecute() const {return(_gradeToExecute);}

const char *Form::GradeTooHighException::what() const throw() {return ("Grade too high!");}

const char *Form::GradeTooLowException::what() const throw() {return ("Grade too Low!");}

std::ostream &operator<<(std::ostream &stream, Form const &other) {
	stream << other.getName()
	<< " requires grade " << other.getGradeToSign()
	<< " to sign and grade " << other.getGradeToExecute()
	<< " to execute. Form signature status = " << other.getIsSigned() << std::endl;
	return (stream);
}
