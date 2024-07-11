/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:34:04 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:54:18 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	john("john", 1);
	Intern		bobby;
	AForm		*form = NULL;
	std::string	nameForm[4] = {
		"presidential",
		"robotomy",
		"shrubbery",
		"Error 404 - not found"
	};

	std::cout << john ;

	std::cout << "===========================" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		try {
			std::cout << nameForm[i] << std::endl;
			form = bobby.makeForm(nameForm[i], "Random Target");
			john.signForm(*form);
			john.executeForm(*form);
			delete form;
			std::cout << "===========================" << std::endl;
		}
		catch (std::exception &e)
		{ std::cerr << e.what() << std::endl; }
	}
}
