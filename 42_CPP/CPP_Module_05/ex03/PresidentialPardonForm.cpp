/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:19:00 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:20:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

PresidentialPardonForm::PresidentialPardonForm(void) :
    AForm("PresidentialPardonForm", false, 25, 5), _target("unknown") {
    // std::cout << "Presidential default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
    // std::cout << "Presidential constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
    AForm(src.getFormName(), src.getSignedStatus(), src.getGradeToSign(),
    src.getGradeToExecute()) {

    // std::cout   << "Copy constructor of " << this->getFormName() << " called."
    //             << std::endl;
    this->_target = src._target;
	return ; // verifier pour le name appele dans stdout.
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	// std::cout	<< "Assignation operator of " << src.getFormName() << " called."
	// 			<< std::endl;
	if (this != &src)
        this->_target = src._target;
	return *this;
} // l'objet existe deja donc pas besoin du constructeur de AForm !

PresidentialPardonForm::~PresidentialPardonForm() {
    // std::cout << "Robotomy destructor called." << std::endl;
    return ;
}

/***************************** OTHER FUNCTIONS ******************************/

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const {

    if ((this->getSignedStatus())
		&& (executor.getGrade() < this->getGradeToExecute()))
        std::cout << _target << " has been pardoned by Zaphod." << std::endl;
    else
         throw (AForm::GradeTooLowException());
}
