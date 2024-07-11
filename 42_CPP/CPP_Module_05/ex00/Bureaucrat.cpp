/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 14:26:53 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(0){
	std::cout << "Default Bureaucrat constructor is called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) :
			_name(name), _grade(grade) {
	std::cout	<< "Bureaucrat constructor for : " << name << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name),
				_grade(src._grade) {
	std::cout << "Copy constructor of " << _name << " called." << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {

	std::cout << "Assignation operator of " << _name << " called." << std::endl;
	if (this != &src)
		this->_grade = src._grade;
		// pas d'affectation de _name car c'est une const (propre a l'objet)
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor for " << _name << " is called." << std::endl;
	return ;
}

/********************************* GETTERS **********************************/

std::string	const Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int	 Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

/***************************** OTHER FUNCTIONS ******************************/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is already the highest!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is already the lowest!";
}

void	Bureaucrat::downGrade(void) {

	// si on est deja en bas, on ne peut pas retrograder ->erreur
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else {
		this->_grade--;
		std::cout << "Sorry you've been retrogaded.. " << std::endl; }
}

void	Bureaucrat::upGrade(void) {

	// si on est deja en haut, on ne peut pas monter ->erreur
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else {
		this->_grade++;
		std::cout	<< "Congrats! Soon you'll be President of the World !"
				<< std::endl; }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {

	std::cout << "Name : " << bureaucrat.getName() << std:: endl;
	std::cout << "Grade : " << bureaucrat.getGrade() << std::endl;
	return out;
}
