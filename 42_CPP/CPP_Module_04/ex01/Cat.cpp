/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:55 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:59:05 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Cat::Cat() : _type("Cat") {

	std::cout << "Cat default constructor called." << std::endl;
	this->_catBrain = new Brain;
	return ;
}

Cat::Cat(const Cat &src) : Animal(src) {

	std::cout << "Copy Cat operator is called." << std::endl;
	this->_type = src._type;
	return ;
}

Cat &Cat::operator=(const Cat &src) {

	if (this != &src) {
		Animal::operator=(src);
		this->_type = src._type;
		std::cout << "Cat assignation operator called." << std::endl;
	}
	return *this;
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl;
	delete _catBrain;
	return ;
}

/********************************** GETTER **********************************/

std::string	Cat::getType(void) const {

	return (this->_type);
}

Brain	*Cat::getBrain(void) const {

	return (_catBrain);
}

/****************************** OTHER FUNCTION *******************************/

void	Cat::makeSound() const {

	std::cout << "And the " << this->_type << " says MEEOOOOW!" << std::endl;
	return ;
}

void	Cat::printIdeas(void) const {

	this->_catBrain->printIdeas();
	return ;
}
