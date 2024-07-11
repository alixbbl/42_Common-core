/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:16:13 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/20 16:54:43 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

AMateria::AMateria() : _type("default") {

	std::cout << "AMateria default constructor called" << std::endl;
	return ; }

AMateria::AMateria(std::string const &type) : _type(type) {

	std::cout << "AMateria -" << type << "- constructor called" << std::endl;
	return ; }


AMateria::AMateria(const AMateria &src) {

	this->_type = src._type;
	std::cout << "AMateria copy operator called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src) {

	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria::~AMateria() {

	std::cout << "AMateria destructor called" << std::endl;
	return ; }


/***************************** OTHER FUNCTIONS ******************************/

std::string const	&AMateria::getType() const {
	return (_type); }


void	AMateria::use(ICharacter& target) {

	std::cout	<< "Materia is used against target : " << target.getName()
				<< std::endl;
	return ; }

/*
La fonction clone() n'est pas implementee car virtuelle pure, or c'est la plus
importante des fonctions de cet exercice. Il s'agit d'une fonction utilisee pour
realiser une copie profonde d'un objet, et qui doit etre implementee dans la classe
de base. On pourrait la coder de la maniere suivante :

class AMateria {
public:
    virtual AMateria* clone() const = 0;
    // ...
};

class ConcreteMateria : public AMateria {
public:
    virtual ConcreteMateria* clone() const {
        return new ConcreteMateria(*this);  // Utilisation de new pour créer une nouvelle instance
    }
    // ...
};

*/
