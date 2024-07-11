/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:20 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 16:25:39 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/************************* CONSTRUCTORS & DESTRUCTOR ***************************/

Fixed::Fixed() : _raw_bits(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {

    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _raw_bits = other.getRawBits(); }
    return *this;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {

    return _raw_bits;
} // retourne valeur du nbr a virg.fixe sans la convertir.

void    Fixed::setRawBits( int const raw ) {

    _raw_bits = raw;
    return ;
}

/******************************** EX 01 - NEW *****************************/

Fixed::Fixed(const int integer) {

    std::cout << "Int constructor called" << std::endl;
    _raw_bits =  (integer << _fract_bits);
}
/* par exemple :
si integer = 5, sa notation binaire est 00000101.
On effectue la conversion, le 00000101 devient :
=> 0000010100000000, or les 8 derniers bits sont la partie fractionnaire.
Donc on pourra utliser ceci pour convertir.
*/

Fixed::Fixed(const float floater) {

    std::cout << "Float constructor called" << std::endl;
    _raw_bits = std::roundf(floater * (1 << _fract_bits));
}
/* On veut convertir un float en nbr virgule fixe avec 8 bits en partie
fractionnaire. Operation avec la norme IEAA se.....m.
On multiplie le floater par 2ˆ8, puis on arrondit le resultat avec le carre
ici, la fonction roundf. Le resultat est la representation du float en nbr
a virgule fixe.
Exemple : on convertit 9,14.
9,14 * 2ˆ8 = 2342,24 => 2342, soit 2342,00000000.
*/

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw_bits / (1 << _fract_bits)); }


int		Fixed::toInt(void) const
{
	return (_raw_bits >> _fract_bits); }


std::ostream	&operator<<(std::ostream &outstream, Fixed const &other) // important
{
	outstream << other.toFloat();
	return (outstream); }
