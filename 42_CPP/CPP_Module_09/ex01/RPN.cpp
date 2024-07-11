/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:58:55 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/24 13:13:18 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

RPN::RPN() : _nb(0) { return ; }

RPN::RPN(const RPN &src) {
	this->_stackRPN = src._stackRPN;
}

RPN &RPN::operator=(const RPN &src) {
	(void)src;
	return *this;
}

RPN::~RPN() { return ; }

/***************************** OTHER FUNCTIONS ********************************/

void	RPN::divisionByZeroDetection(std::string input) {

	std::string div = "0/";
	if (input.find(div) != std::string::npos)
		throw RPN::divisionByZero();
}

bool	RPN::isValidOperand(char c) {

	char tab[] = {'+', '-', '/', '*'};
	for (int i = 0; i < 4; i++) {
		if (c == tab[i])
			return true; }
	return false;
}

void	RPN::executeOperation(char c) {

	int op1 = this->_stackRPN.top();  // on prend le premier du haut de la stack;
	this->_stackRPN.pop();
	_nb--;
	int op2 = this->_stackRPN.top(); // puis le second
	this->_stackRPN.pop();
	_nb--;
	int result = 0;

	switch(c) {

		case '+' :
		result = op2 + op1;
		break ;

		case '-' :
		result = op2 - op1;
		break ;

		case '*' :
		result = op2 * op1;
		break ;

		case '/' :
		result = op2 / op1;
		break ;
	}
	this->_stackRPN.push(result); // on met le resultat dans la stack
	_nb++;
}

//gestion du cas ou operation impossible car "3 + * 6" par exemple.
void	RPN::execute(char *str) {

	std::string input(str); // on convertit de char* a string pour utiliser string.h
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end()); // suppression ' '

	if (input.empty()) {
		std::cerr << "Empty argument" << std::endl;
			return ; }
	divisionByZeroDetection(input);
	for (size_t i = 0; i < input.size(); i++)
	{
		try {
			if (isdigit(input[i])) {
				this->_nb++;
				this->_stackRPN.push(static_cast<int>(input[i]) - '0'); }
			else if (isValidOperand(input[i]) and this->_nb >= 1) {
					executeOperation(input[i]); }
			else
				throw RPN::isNotADigitorValidOperand();
		}
		catch (const std::exception &e) { std::cerr << e.what() << std::endl; return ; }
	}
	if (_nb == 1 && _stackRPN.size() == 1)
		std::cout << "Result : " << _stackRPN.top() << std::endl;
	else {
		std::cerr << "Invalid RPN expression." << std::endl;
		return ; }
}

/******************************** EXCEPTIONS **********************************/

const char* RPN::badInput::what() const throw() {
		return ("Error : input is not valid"); }

const char* RPN::isNotADigitorValidOperand::what() const throw() {
		return ("Error : a valid operand or input is required."); }

const char* RPN::divisionByZero::what() const throw() {
		return ("Error : division by zero is forbidden."); }
