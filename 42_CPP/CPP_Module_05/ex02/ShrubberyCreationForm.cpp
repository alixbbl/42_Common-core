/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:19:17 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:07:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
/*
Grades requis : signature 145, exécution 137
Crée un fichier <cible>_shrubbery dans le répertoire de travail et écrit des arbres
ASCII à l'intérieur.
*/

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm",
	false, 145, 137), _target("unknown") {
	std::cout << "Shrubbery default constructor is called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {
	std::cout << "Shrubbery target constructor is called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	AForm(src.getFormName(), src.getSignedStatus(), src.getGradeToSign(),
	src.getGradeToExecute()) {
	std::cout   << "Copy constructor of " << src.getFormName() << " called."
                << std::endl;
    this->_target = src._target;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout	<< "Assignation operator of " << this->getFormName() << " called."
				<< std::endl;
	if (this != &src)
        this->_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor is called." << std::endl;
	return ;
}

/***************************** OTHER FUNCTIONS ******************************/

void    treeFunction(std::string target) {

    std::ofstream outfile; // on cree un fichier out.
    outfile.open((target + "_shrubbery").c_str()); // on l'open ensuite
    outfile <<"                                  # #### ####" << std::endl
		<< "                                ### \\/#|### |/####" << std::endl
		<< "                               ##\\/#/ \\||/##/_/##/_#" << std::endl
		<< "                             ###  \\/###|/ \\/ # ###" << std::endl
		<< "                           ##_\\_#\\_\\## | #/###_/_####" << std::endl
		<< "                          ## #### # \\ #| /  #### ##/##" << std::endl
		<< "                           __#_--###`  |{,###---###-~" << std::endl
		<< "                                     \\ }{" << std::endl
		<< "                                      }}{" << std::endl
		<< "                                      }}{" << std::endl
		<< "                                      {{}" << std::endl
		<< "                                , -=-~{|}.-^- _" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    if ((this->getSignedStatus())
		&& (executor.getGrade() <= this->getGradeToExecute()))
        treeFunction(_target);
    else
        throw (AForm::GradeTooLowException()); }
