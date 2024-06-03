/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:53:16 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/03 20:36:38 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
	Intern(void);
	Intern(Intern const &other);
	~Intern(void);

	Intern &operator=(Intern const &other);

	AForm *makeForm(std::string formName, std::string target);
	AForm *createShrubberyCreationForm(std::string target) const;
	AForm *createRobotomyRequestForm(std::string target) const;
	AForm *createPresidentialPardonForm(std::string target) const;


	class FormNotFoundException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
};

#endif
