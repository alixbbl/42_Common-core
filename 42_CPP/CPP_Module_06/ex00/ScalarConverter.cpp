/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:30:43 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/19 14:28:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdio>
#include <climits>

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

ScalarConverter::ScalarConverter() {

	std::cout << "Default constructor called." << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter() {

	std::cout << "Destructor called." << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {

	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {

	std::cout << "Assignation operator called." << std::endl;
	(void)src;
	return (*this);
}

/***************************** PUBLIC FUNCTIONS *******************************/

bool	ScalarConverter::isChar(const std::string &literal) {

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return true;
	return false;
}

bool	ScalarConverter::isInt(const std::string &literal) {

	if (std::atol(literal.c_str()) < INT_MIN || std::atol(literal.c_str()) > INT_MAX)
		return false;
	unsigned int i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (i == literal.length())
		return true;
	return false;
}

bool	ScalarConverter::isFloat(const std::string &literal) {

	unsigned long	i = 0;

	if (literal == "-inff" or literal == "+inff" or literal == "nanf")
		return (true);
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == '.' && std::isdigit(literal[i + 1]))
		i++;
	else
		return (false);
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == 'f')
		i++;
	else
		return (false);
	if (literal.size() == i)
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string &literal) {

	unsigned long	i = 0;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	if (literal[0] == '-' || literal[0] == '-')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == '.' && std::isdigit(literal[i + 1]))
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal.size() == i)
		return (true);
	return (false);
}

/* Fonctions simples d'impression */
void ScalarConverter::printChar(char c) {

	if (!std::isgraph(c))
		std::cout << "char : Non displayable." << std::endl;
	else
		std::cout << "char is : " << c << std::endl;
}

void ScalarConverter::printInt(int a) {
	std::cout << "int is : " << a << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float is : " << f << ".0f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double is : " << d << ".0" << std::endl;
}


/* Fonctions de conversion vers le type voulu : */
void	ScalarConverter::convertChar(char c) {

	printChar(c);
	printInt(static_cast<int>(c)); // upcasting
	printFloat(static_cast<float>(c)); // upcasting
	printDouble(static_cast<double>(c)); // upcasting
}

void	ScalarConverter::convertInt(int a) {

	if (a > 0 && a < 256)
		printChar(static_cast<char>(a)); // upcasting + parsing
	else
		std::cout << "char is not printable." << std::endl;
	printInt(a);
	printFloat(static_cast<float>(a)); // downcasting
	printDouble(static_cast<double>(a)); // downcasting
}

void ScalarConverter::convertFloat(float f, std::string str) {

	if (str == "-inff" or str == "+inff" or str == "nanf") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << str << std::endl;
		str.erase(str.length() - 1,1); // permet de supprimer le dernier caractere
		std::cout << "double : " << str << std::endl;
	}
	else {
		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
}

void ScalarConverter::convertDouble(double d, std::string str) {

	if (str == "-inf" or str == "+inf" or str == "nan") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : "<< str + 'f' << std::endl;
		std::cout << "double : " << str << std::endl;
	}
	else {
		printChar(static_cast<char>(d));
		if (d > INT_MAX or d < INT_MIN)
			std::cout << "int : impossible" << std::endl;
		else
			printInt(static_cast<int>(d));
		if (d > __FLT_MAX__)
			std::cout << "float: +inf" << std::endl;
		else if (d < __FLT_MIN__)
			std::cout << "float: -inf" << std::endl;
		else
			printFloat(static_cast<float>(d));
		printDouble(d);
	}
}

/* Fonction combinee avec convert(), retenir la methode associee au switch et pointeur sur f()*/
int		ScalarConverter::determineType(const std::string &literal) {

	int	typeTab[4] = {1, 2, 3, 4};
	bool (*typeArray[4])(const std::string &literal) = {isChar, isInt, isFloat, isDouble};

	for (int i = 0; i < 4; i++) {
		if (typeArray[i](literal) == true)
			return typeTab[i]; }
	return 0;
}

/* Fonction de conversion generale :*/
void ScalarConverter::convert(const std::string &literal) {

	char literalChar;
	int literalInt;
	float literalFloat;
	double literalDouble;

	int	type = determineType(literal);

	switch (type) {

		case CHAR :
			std::cout << "Type is CHAR "  << std::endl;
			literalChar = literal[0];
			convertChar(literalChar);
			break ;
		case INT :
			std::cout << "Type is INT "<< std::endl;
			literalInt = atoi(literal.c_str());
			convertInt(literalInt);
			break ;
		case FLOAT :
			std::cout << "Type is FLOAT "<< std::endl;
			literalFloat = std::atof(literal.c_str());
			convertFloat(literalFloat, literal); // on envoie la conversion de literal en float ET literal
			break ;
		case DOUBLE :
			std::cout << "Type is DOUBLE " << std::endl;
			literalDouble = std::strtod(literal.c_str(), NULL);
			convertDouble(literalDouble, literal); // idem, deux arguments pout les verifs
			break ;
		default :
			std::cout << "char : impossible to convert and print." << std::endl;
			std::cout << "int : impossible to convert and print." << std::endl;
			std::cout << "float : impossible to convert and print." << std::endl;
			std::cout << "double : impossible to convert and print." << std::endl;
	}
}

// std::cout << "TEST" << std::endl;
