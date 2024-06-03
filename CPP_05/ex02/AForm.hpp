/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:33 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 19:06:56 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	AForm();

	public:
	AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm			&operator=(const AForm &other);
	void			beSigned(const Bureaucrat &other);
	std::string		getName(void) const;
	bool			getIsSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExecute(void) const;
	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, AForm const &other);


#endif
