/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:48 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:59:28 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Dog::Dog (void) : _type("Dog") {

	std::cout << "Dog default constructor called" << std::endl;
	this->_dogBrain = new Brain;
	return ;
}

Dog::Dog (const Dog &src) : Animal(src) {

	this->_type = src._type;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog &Dog::operator=(const Dog &src) {

	if (this != &src) {
		Animal::operator=(src);
		this->_type = src._type;
		std::cout << "Dog assignation operator called" << std::endl;
	}
	return *this;
}

Dog::~Dog(void) {

	delete _dogBrain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

/********************************** GETTER **********************************/

std::string	Dog::getType(void) const {

	return (this->_type);
}

Brain	*Dog::getBrain(void) const {

	return _dogBrain;
}

/****************************** OTHER FUNCTION ******************************/

void	Dog::makeSound(void) const {

	std::cout << "And the " << this->_type << " says WOOF!" << std::endl;
	return ;
}

void	Dog::printIdeas(void) const {

	this->_dogBrain->printIdeas();
	return ;
}
