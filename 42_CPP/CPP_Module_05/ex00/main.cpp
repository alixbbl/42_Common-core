/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:34:04 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 10:19:04 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define GRADE_MAX 1
#define GRADE_MIN 150

int main(void)
{
	// TEST 1
	std::cout << "-------------- TEST 1 --------------" << std::endl;
	try {
		Bureaucrat bureaucrat("Patoche", 150);
		std::cout << bureaucrat;
		bureaucrat.downGrade(); }

	catch (const Bureaucrat::GradeTooLowException& exception) {
		std::cout	<< "Grade Exception caught is : " << exception.what()
					<< std::endl; }

	// TEST 2
	std::cout << std::endl;
	std::cout << "-------------- TEST 2 --------------" << std::endl;
	try {
		Bureaucrat bureaucrat("Big Boss", 1);
		std::cout << bureaucrat;
		bureaucrat.upGrade(); }

	catch (const Bureaucrat::GradeTooHighException& exception) {
		std::cout	<< "Grade Exception caught is : " << exception.what()
					<< std::endl; }

	catch (const std::exception& exception) { // pour tout autre type
		std::cout	<< "Caught std::exception: " << exception.what()
					<< std::endl; }

	// TEST 3
	std::cout << std::endl;
	std::cout << "-------------- TEST 3 --------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Le Stagiaire", 154);
		Bureaucrat bureaucrat2(bureaucrat1); }

	catch (const std::exception& exception) {
		std::cout	<< "Caught std::exception: " << exception.what()
					<< std::endl; }

	// TEST 4
	std::cout << std::endl;
	std::cout << "-------------- TEST 4 --------------" << std::endl;
	try {
		Bureaucrat bureaucrat("Sylvie de la Compta", 83);
		std::cout << bureaucrat;
		bureaucrat.upGrade(); }

	catch (const Bureaucrat::GradeTooHighException& exception) {
		std::cout	<< "Grade Exception caught is : " << exception.what()
					<< std::endl; }

	catch (const std::exception& exception) {
		std::cout	<< "Caught std::exception: " << exception.what()
					<< std::endl; }

	// TEST 5
	std::cout << std::endl;
	std::cout << "-------------- TEST 5 --------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Le fils du patron", 37);
		Bureaucrat bureaucrat2(bureaucrat1); }

	catch (const std::exception& exception) {
		std::cout	<< "Caught std::exception: " << exception.what()
					<< std::endl; }

	return 0;
}

/*
La syntaxe obligatoire sur les blocs catch est la suivante :

	catch (type const& e){...}, on utilise le passage de references pour
	eviter de traiter une copie et preserver le polymorphisme de l'objet
	cas echeant (SAUF pour les int).

	Exemple :

	int division(int a,int b) {

	try // on teste un code "dangereux"
    {
        if(b == 0)
           throw string("Division par zéro !");
        else
           return a/b;
   	}
   	catch(string const& chaine) // on "attrape" l'objet de throw.
	{
       cerr << chaine << endl; }
}
*/
