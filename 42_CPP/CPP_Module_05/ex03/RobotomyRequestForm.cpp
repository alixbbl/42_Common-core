/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:18:49 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:21:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", false, 72, 45),
    _target("unknown") {
    // std::cout << "Robotomy default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45),
    _target(target) {
    // std::cout << "Robotomy target constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
    AForm(src.getFormName(), src.getSignedStatus(), src.getGradeToSign(),
    src.getGradeToExecute()) {

    // std::cout   << "Copy constructor of " << this->getFormName() << " called."
    //             << std::endl;
    this->_target = src._target;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	// std::cout	<< "Assignation operator of " << src.getFormName() << " called."
	// 			<< std::endl;
	if (this != &src)
        this->_target = src._target;
	return *this;
} // l'objet existe deja donc pas besoin du constructeur de AForm !

RobotomyRequestForm::~RobotomyRequestForm() {
    // std::cout << "Robotomy destructor called." << std::endl;
    return ;
}

/***************************** OTHER FUNCTIONS ******************************/

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    std::cout << "***DRILLIIIIIIING NOOOIIIIISE***" << std::endl;
    if ((this->getSignedStatus())
		&& (executor.getGrade() <= this->getGradeToExecute()))
        std::cout << this->_target << " has been 50% robotized !" << std::endl;
    else
         throw (AForm::GradeTooLowException());
}
// modifier la fonction ?? je comprends pas la consigne ! pourquoi en deux temps ?
