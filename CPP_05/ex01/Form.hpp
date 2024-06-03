/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:33 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 16:53:55 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	Form();

	public:
	Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &other);
	~Form();

	Form			&operator=(const Form &other);
	void			beSigned(const Bureaucrat &other);
	std::string		getName(void) const;
	bool			getIsSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExecute(void) const;

	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, Form const &other);


#endif
