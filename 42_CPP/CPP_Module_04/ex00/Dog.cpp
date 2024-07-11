/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:48 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 09:47:12 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Dog::Dog (void) : _type("Dog") {

	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog (const Dog &src) : Animal(src) {

	this->_type = src._type;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}
/* Cette syntaxe au niveau de l' operateur de recopie est appelee "construction
par copie de la base", on utilise la recopie de Animal pour recopier Dog ensuite*/

/* Ce n' est pas applicable a la surcharge car on traite deja un Dog, il n'y
a donc aucun besoin de faire appel a un constructeur .*/
Dog &Dog::operator=(const Dog &src) {

	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return *this;
}

Dog::~Dog(void) {

	std::cout << "Dog destructor called." << std::endl;
	return ;
}

/********************************** GETTER **********************************/

std::string	Dog::getType(void) const {

	return (this->_type);
}

/****************************** OTHER FUNCTION ******************************/

void	Dog::makeSound(void) const {

	std::cout << "And the " << this->_type << " says WOOF!" << std::endl;
	return ;
}
