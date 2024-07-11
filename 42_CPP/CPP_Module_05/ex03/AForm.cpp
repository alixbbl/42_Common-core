/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:19:41 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

AForm::AForm(void) : _formName("unknown"), _signed(false), _gradeToSign(1),
				_gradeToExecute(1) {
	// std::cout << "Default AForm constructor is called." << std::endl;
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
		// std::cout << "AForm constructor is called." << std::endl;
	return ;
}

AForm::AForm(const AForm &src) : _formName(src._formName), _signed(src._signed),
				_gradeToSign(src._gradeToSign),
				_gradeToExecute(src._gradeToExecute) {
	// std::cout << "Copy constructor of " << _formName << " called." << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &src) {

	// std::cout	<< "Assignation operator of " << _formName << " called."
				// << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

AForm::~AForm() {
	// std::cout << "AForm destructor is called." << std::endl;
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

std::ostream &operator<<(std::ostream &out, const AForm &aform) {

	std::cout << "Name : " << aform.getFormName() << std:: endl;
		std::cout << "Signed status : " << aform.getSignedStatus() << std:: endl;
			std::cout << "Req. grade to sign : " << aform.getGradeToSign() << std:: endl;
				std::cout << "Req. grade to exec : " << aform.getFormName() << std:: endl;
	return out;
}

void    AForm::beSigned(Bureaucrat &bureaucratos) {

	if (bureaucratos.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}
