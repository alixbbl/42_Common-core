/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:18:12 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:53:03 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Intern::Intern(void) {
	// std::cout << "Default Intern constructor called." << std::endl;
	return ;
}

Intern::Intern(const Intern &src) {
    (void)src;
	// std::cout << "Copy constructor of Intern called." << std::endl;
	return ;
}

Intern &Intern::operator=(Intern const &src) {
	(void)src;
    // std::cout	<< "Assignation operator of Intern called." << std::endl;
	return *this;
}

Intern::~Intern() {
    // std::cout << "Intern destructor is called." << std::endl;
	return ;
}

/***************************** OTHER FUNCTIONS ******************************/

AForm* Intern::makeForm(std::string name, std::string target) {

    std::string formsName[3] = { "presidential", "robotomy", "shrubbery" };

    AForm* forms[3] = {
        new PresidentialPardonForm(target),
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target) };

    AForm* ret = NULL; // valeur du retour par defaut a NULL

    for (int i = 0; i < 3; i++) {
        if (name == formsName[i])
            ret = forms[i];
        else
            delete forms[i]; }

    if (ret != NULL) {
        std::cout << "Intern creates " << ret->getFormName() << std::endl;
        std::cout << ret->getFormName() << std::endl;
        return ret; }
    else
        throw Intern::FormNotFound();
}

// Nouvelle classe d'exception
const char *Intern::FormNotFound::what() const throw() {
    return ("Form not found! Sorry boss!");
}
