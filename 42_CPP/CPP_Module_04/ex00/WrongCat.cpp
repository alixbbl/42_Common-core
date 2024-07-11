/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:37 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:55:13 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

WrongCat::WrongCat() : _type("Wrong Kitty") {

	std::cout << "WRONGCat default constructor called." << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {

	std::cout << "Copy WrongCat operator is called." << std::endl;
	this->_type = src._type;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {

	if (this != &src) {
		// WrongAnimal::operator=(src); autre syntaxe possible.
		this->_type = src._type;
		std::cout << "WrongCat assignation operator called." << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

/********************************** SETTER **********************************/

std::string	WrongCat::getType(void) const {

	return (this->_type); }

/****************************** OTHER FUNCTION *******************************/

void	WrongCat::makeSound() const {

	std::cout << "And the " << this->_type << " says FUCK YOU!" << std::endl;
	return ; }
