/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:26:44 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 15:43:42 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/************************* CONSTRUCTORS & DESTRUCTOR ***************************/

Fixed::Fixed() : _raw_bits(0) {
	std::cout << "Default constructor called" << std::endl;
} // constructeur par defaut

Fixed::Fixed(const Fixed &other) {

    std::cout << "Copy constructor called" << std::endl;
    *this = other;
} // constructeur de recopie, on initialise la valeur de la copie
// avec la valeur du modele qui se trouve etre other ici. Creation d'une instance.

Fixed &Fixed::operator=(const Fixed &other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_raw_bits = other.getRawBits(); }
    return *this;
}
// surcharge de l'operateur d'affectation, on return une reference sur un
// objet de type Fixed.


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
} // destructeur

/***************************** OTHER FUNCTIONS *******************************/

int Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return _raw_bits;
} // retourne valeur du nbr a virg.fixe sans la convertir.


void    Fixed::setRawBits( int const raw ) {

    _raw_bits = raw;
    return ;
} // initialise la valeur du nbr a virgfixe depuis celle passee en param.
