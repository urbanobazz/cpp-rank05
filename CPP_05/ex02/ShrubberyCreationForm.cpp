/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:39:20 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/04 11:22:45 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other)
	{
		this->_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw ("Form is not signed!");
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outFile((this->_target + "_shrubbery").c_str());
	if (!outFile.is_open())
		throw ("Unable to open file!");
	outFile << "                                       .\n"
		"                                              .         ;  \n"
		"                 .              .              ;%     ;;   \n"
		"                   ,           ,                :;%  %;   \n"
		"                    :         ;                   :;%;'     .,   \n"
		"           ,.        %;     %;            ;        %;'    ,;\n"
		"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
		"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
		"                `%;.     ;%;     %;'         `;%%;.%;'\n"
		"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
		"                    `:%;.  :;bd%;          %;@%;'\n"
		"                      `@%:.  :;%.         ;@@%;'   \n"
		"                        `@%.  `;@%.      ;@@%;         \n"
		"                          `@%%. `@%%    ;@@%;        \n"
		"                            ;@%. :@%%  %@@%;       \n"
		"                              %@bd%%%bd%%:;     \n"
		"                                #@%%%%%:;;\n"
		"                                %@@%%%::;\n"
		"                                %@@@%(o);  . '         \n"
		"                                %@@@o%;:(.,'         \n"
		"                            `.. %@@@o%::;         \n"
		"                               `)@@@o%::;         \n"
		"                                %@@(o)::;        \n"
		"                               .%@@@@%::;         \n"
		"                               ;%@@@@%::;.          \n"
		"                              ;%@@@@%%:;;;. \n"
		"                          ...;%@@@@@%%:;;;;,..\n";
	outFile.close();
}
