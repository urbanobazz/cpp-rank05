/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:17:46 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 19:01:29 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		Bureaucrat(void);

	public:
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &other);

		std::string getName(void) const;
		unsigned int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(AForm &other);
		void executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
			public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other);

#endif
