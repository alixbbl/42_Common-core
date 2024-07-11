/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 16:46:17 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

AForm::AForm() : _formName("unknown"), _signed(false), _gradeToSign(150),
				_gradeToExecute(150) {
	std::cout << "Default AForm constructor is called." << std::endl;
	return ;
}

AForm::AForm(std::string const nameForm, bool status, const unsigned int gradeToSign,
			const unsigned int gradeToExec) : _formName(nameForm), _signed(status),
				_gradeToSign(gradeToSign), _gradeToExecute(gradeToExec) {
	if (_gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else if (_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else
		std::cout << "Form constructor "<< _formName << " is called." << std::endl;
	return ;
}

AForm::AForm(const AForm &src) : _formName(src._formName), _signed(src._signed),
				_gradeToSign(src._gradeToSign),
				_gradeToExecute(src._gradeToExecute) {
	std::cout << "Copy constructor of " << src._formName << " called." << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &src) {

	std::cout	<< "Assignation operator of " << src._formName << " called."
				<< std::endl;
	if (this != &src)
		this->_signed = src.getSignedStatus();
		// pas d'affectation de _name car c'est une const (propre a l'objet)
	return *this;
}

AForm::~AForm() {
	std::cout << "Form destructor is called." << std::endl;
	return ;
}

/********************************* GETTERS **********************************/

std::string const AForm::getFormName(void) const {
	return (_formName);
}

bool AForm::getSignedStatus(void) const {
	return (_signed);
}

unsigned int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

/***************************** OTHER FUNCTIONS ******************************/

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {

	std::cout << "Name : " << form.getFormName() << std:: endl;
		std::cout << "Signed status : " << form.getSignedStatus() << std:: endl;
			std::cout << "Req. grade to sign : " << form.getGradeToSign() << std:: endl;
				std::cout << "Req. grade to exec : " << form.getFormName() << std:: endl;
	return out;
}

/* NEW FUNCTION EX01 */

void   AForm::beSigned(Bureaucrat &bureaucratos) {

	if (bureaucratos.getGrade() <= this->_gradeToSign) {

		std::cout << this->_formName << " is now signed." << std::endl;
		this->_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}
