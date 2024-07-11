/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:05:37 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 14:46:24 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

AAnimal::AAnimal() : _type("default") {

	std::cout << "AAnimal default constructor called" << std::endl;
	return ; }

AAnimal::AAnimal (const AAnimal &src) {

	std::cout << "AAnimal copy operator called" << std::endl;
	this->_type = src._type;
	return ; }

AAnimal &AAnimal::operator=(const AAnimal &src) {

	if (this != &src)
	{
		this->_type = src._type;
		std::cout << "AAnimal assignation operator called" << std::endl;
	}
	return *this; }

AAnimal::~AAnimal() {

	std::cout << "AAnimal destructor called" << std::endl;
	return ; }

/*********************************** GETTER **********************************/

std::string	AAnimal::getType(void) const {

	return this->_type; }

/****************************** OTHER FUNCTIONS ******************************/

void	AAnimal::makeSound(void) const {

	std::cout << "An AAnimal doing some AAnimal noise." << std::endl;
	return ; }
