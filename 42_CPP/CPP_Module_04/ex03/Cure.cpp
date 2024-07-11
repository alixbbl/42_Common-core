/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:16:40 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 11:43:17 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called" << std::endl;
	return;
}

Cure::Cure(const Cure &src) : AMateria(src) {

	this->_type = src._type;
	std::cout << "Cure copy operator called" << std::endl;
}

Cure	&Cure::operator=(const Cure &src) {

	std::cout << "Cure copy operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type; }
	return *this;
}

Cure::~Cure() {

	std::cout << "Cure destructor called" << std::endl;
	return ;
}


/***************************** OTHER FUNCTIONS ******************************/

Cure*	Cure::clone(void) const {

	Cure* newCure = new Cure;
	return newCure;
}

void	Cure::use(ICharacter& target) {

	std::cout	<< "* heals " << target.getName() << "'s wounds"
				<< " *" << std::endl;
	return ;
}
