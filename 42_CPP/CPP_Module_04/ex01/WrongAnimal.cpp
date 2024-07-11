/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:40 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 14:00:07 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

WrongAnimal::WrongAnimal() : _type("I'm Wrong !") {

	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal (const WrongAnimal &src) {

	std::cout << "WrongAnimal copy operator called" << std::endl;
	this->_type = src._type;
	return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {

	if (this != &src) {
		this->_type = src._type;
		std::cout << "WrongAnimal assignation operator called" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

/*********************************** GETTER **********************************/

std::string	WrongAnimal::getType(void) const {

	return this->_type;
}

/****************************** OTHER FUNCTIONS ******************************/

void	WrongAnimal::makeSound(void) const {

	std::cout << "An WrongAnimal doing some WrongAnimal noise." << std::endl;
	return ;
}
