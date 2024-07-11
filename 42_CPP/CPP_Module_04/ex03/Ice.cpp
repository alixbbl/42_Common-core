/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:18:34 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 11:42:15 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
	return;
}

Ice::Ice(const Ice &src) : AMateria(src) {

	this->_type = src._type;
	std::cout << "Ice copy operator called" << std::endl;
}

Ice	&Ice::operator=(const Ice &src) {

	std::cout << "Ice copy operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type; }
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
	return ;
}


/***************************** OTHER FUNCTIONS ******************************/

Ice*	Ice::clone(void) const { // retourne pointeur sur nuvel objet Ice

	Ice* newIce = new Ice;
	return newIce;
}

void	Ice::use(ICharacter& target) {

	std::cout	<< "* shoots an ice bolt at " << target.getName()
				<< " *" << std::endl;
	return ;
}
