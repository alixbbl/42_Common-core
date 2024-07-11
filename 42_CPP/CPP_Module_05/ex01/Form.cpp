/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 10:23:47 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Form::Form() : _formName("unknown"), _signed(false), _gradeToSign(150),
				_gradeToExecute(150) {
	std::cout << "Default Form constructor is called." << std::endl;
	return ;
}

// on peut completer en parsant les init avec le retour execeptions a etoffer
Form::Form(std::string const nameForm, bool status, const unsigned int gradeToSign,
			const unsigned int gradeToExec) : _formName(nameForm), _signed(status),
				_gradeToSign(gradeToSign), _gradeToExecute(gradeToExec) {
	if (_gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else
		std::cout << "Form constructor "<< _formName << " is called." << std::endl;
	return ;
}

Form::Form(const Form &src) : _formName(src._formName), _signed(src._signed),
				_gradeToSign(src._gradeToSign),
				_gradeToExecute(src._gradeToExecute) {
	std::cout << "Copy constructor of " << src._formName << " called." << std::endl;
	return ;
}

Form &Form::operator=(Form const &src) {

	std::cout	<< "Assignation operator of " << src._formName << " called."
				<< std::endl;
	if (this != &src)
		this->_signed = src.getSignedStatus();
		// pas d'affectation de _name car c'est une const (propre a l'objet)
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor is called." << std::endl;
	return ;
}

/********************************* GETTERS **********************************/

std::string const Form::getFormName(void) const {
	return (_formName);
}

bool Form::getSignedStatus(void) const {
	return (_signed);
}

unsigned int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

/***************************** OTHER FUNCTIONS ******************************/

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low to sign!";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high to sign!";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {

	std::cout << "Name : " << form.getFormName() << std:: endl;
		std::cout << "Signed status : " << form.getSignedStatus() << std:: endl;
			std::cout << "Req. grade to sign : " << form.getGradeToSign() << std:: endl;
				std::cout << "Req. grade to exec : " << form.getFormName() << std:: endl;
	return out;
}

/* NEW FUNCTION EX01 */

void   Form::beSigned(Bureaucrat &bureaucratos) {

	if (bureaucratos.getGrade() <= this->_gradeToSign) {

		std::cout << this->_formName << " is now signed." << std::endl;
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}
