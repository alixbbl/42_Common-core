/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:05:37 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:48:29 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Animal::Animal() : _type("default") {

	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &src) {

	std::cout << "Animal copy operator called" << std::endl;
	this->_type = src._type;
	return ;
}

Animal &Animal::operator=(const Animal &src) {

	if (this != &src)
	{
		this->_type = src._type;
		std::cout << "Animal assignation operator called" << std::endl;
	}
	return *this;
}

Animal::~Animal() {

	std::cout << "Animal destructor called" << std::endl;
	return ;
}

/*********************************** GETTER *********************************/

std::string	Animal::getType(void) const {

	return this->_type;
}

/****************************** OTHER FUNCTIONS *****************************/

void	Animal::makeSound(void) const {

	std::cout << "Some animal noise!!!" << std::endl;
	return ;
}
