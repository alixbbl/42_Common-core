/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:34:04 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:04:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	// TEST 1
	std::cout << "-------------- TEST 1 --------------" << std::endl;
	try {
		Form badForm("badForm1", false, 90, -1); }
	catch (const std::exception &e) {
		std::cout << "Exception caught is : " << e.what() << std::endl;
	}
	// TEST 2
	std::cout << std::endl;
	std::cout << "-------------- TEST 2 --------------" << std::endl;
	try { //
		Form goodForm("SuperForm", false, 1, 1);
		Bureaucrat bureaucrat1("BOSS", 1);
		bureaucrat1.signForm(goodForm);
	}
	catch (const Bureaucrat::GradeTooLowException& exception) {
		std::cout	<< "Exception caught is :" << exception.what()
					<< std::endl; }
	// TEST 3
	std::cout << std::endl;
	std::cout << "-------------- TEST 3 --------------" << std::endl;
	try {
		Form badForm("badForm2", false, 0, 6); }
	catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
	return 0;
}
