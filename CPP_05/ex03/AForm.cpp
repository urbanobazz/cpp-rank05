/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:42 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 17:26:15 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) :
_name("DEFAULT_NAME"),
_isSigned(false),
_gradeToSign(1),
_gradeToExecute(1) {return;}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) :
_name(name),
_isSigned(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute) {return;}

AForm::AForm(const AForm &other) :
_name(other._name),
_isSigned(other._isSigned),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute) {return;}

AForm::~AForm(void) {return;}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

void AForm::beSigned(const Bureaucrat &other) {
	if (other.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const {return (_name);}

bool AForm::getIsSigned() const  {return (_isSigned);}

unsigned int AForm::getGradeToSign() const {return (_gradeToSign);}

unsigned int AForm::getGradeToExecute() const {return(_gradeToExecute);}

const char *AForm::GradeTooHighException::what() const throw() {return ("Grade too high!");}

const char *AForm::GradeTooLowException::what() const throw() {return ("Grade too Low!");}

std::ostream &operator<<(std::ostream &stream, AForm const &other) {
	stream << other.getName()
	<< " requires grade " << other.getGradeToSign()
	<< " to sign and grade " << other.getGradeToExecute()
	<< " to execute. AForm signature status = " << other.getIsSigned() << std::endl;
	return (stream);
}
