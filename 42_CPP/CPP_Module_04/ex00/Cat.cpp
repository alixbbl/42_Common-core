/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:55 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 09:47:05 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Cat::Cat() : _type("Cat") {

	std::cout << "Cat default constructor called." << std::endl;
	return ;
};

Cat::Cat(const Cat &src) : Animal(src) {

	std::cout << "Copy Cat operator is called." << std::endl;
	this->_type = src._type;
	return ;
}

Cat &Cat::operator=(const Cat &src) {

	std::cout << "Cat assignation operator called." << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return *this;
}

Cat::~Cat() {

	std::cout << "Cat destructor called." << std::endl;
	return ;
}

/********************************** GETTER **********************************/

std::string	Cat::getType(void) const {

	return (this->_type);
}

/****************************** OTHER FUNCTION *******************************/

void	Cat::makeSound() const {

	std::cout << "And the " << this->_type << " says MEEOOOOW!" << std::endl;
	return ;
}
