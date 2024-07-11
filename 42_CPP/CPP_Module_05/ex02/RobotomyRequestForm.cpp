/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:19:06 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 17:10:29 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", false, 72, 45),
    _target("unknown") {
    std::cout << "Robotomy default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45),
    _target(target) {
    std::cout << "Robotomy target constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
    AForm(src.getFormName(), src.getSignedStatus(), src.getGradeToSign(),
    src.getGradeToExecute()) {

    std::cout   << "Copy constructor of " << this->getFormName() << " called."
                << std::endl;
    this->_target = src._target;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	std::cout	<< "Assignation operator of " << src.getFormName() << " called."
				<< std::endl;
	if (this != &src)
        this->_target = src._target;
	return *this;
} // l'objet existe deja donc pas besoin du constructeur de AForm !

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy destructor called." << std::endl;
    return ;
}

/***************************** OTHER FUNCTIONS ******************************/

void    drill(std::string target) {

    std::srand(time(0));
    if (std::rand() % 2){
        std::cout   << "BZZZZZZZZIIIIIIIH " << target << " has been robotised."
                    << std::endl;
    }
    else
        std::cout   << "Ohhhh" << target<< " has not been robotised - lucky !"
                    << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    if ((this->getSignedStatus())
		&& (executor.getGrade() <= this->getGradeToExecute()))
        drill(_target);
    else
         throw (AForm::GradeTooLowException());
}
