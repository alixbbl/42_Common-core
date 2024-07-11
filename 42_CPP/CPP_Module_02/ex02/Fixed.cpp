/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:47 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 17:05:57 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/************************* CONSTRUCTORS & DESTRUCTOR ***************************/

Fixed::Fixed() : _raw_bits(0) {

	std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &other) {

    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits()); }

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this; }

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits( void ) const {
    return _raw_bits; }

void Fixed::setRawBits( int const raw ) {
    this->_raw_bits = raw; }


/********************************** EX 01 ************************************/

Fixed::Fixed(const int integer) {

    std::cout << "Int constructor called" << std::endl;
    _raw_bits =  (integer << _fract_bits); }

Fixed::Fixed(const float floater) {

    std::cout << "Float constructor called" << std::endl;
   _raw_bits = std::roundf(floater * (1 << _fract_bits)); }

float	Fixed::toFloat(void) const {

	return ((float)_raw_bits / (1 << _fract_bits)); }

int		Fixed::toInt(void) const {
	return (_raw_bits >> _fract_bits); }

std::ostream	&operator<<(std::ostream &stream, Fixed const &other) {

    stream << other.toFloat();
	return (stream); }


/********************************** EX 02 ************************************/

bool	Fixed::operator>(Fixed const &other) const
{
	if (this->_raw_bits > other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &other) const
{
	if (this->_raw_bits < other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	if (this->_raw_bits >= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	if (this->_raw_bits <= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &other) const
{
	if (this->_raw_bits == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	if (this->_raw_bits != other.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &other)
{
	this->_raw_bits += other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &other)
{
	this->_raw_bits -= other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &other)
{
	this->_raw_bits = (this->toFloat() * other.toFloat()) * (1 << _fract_bits);
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &other)
{
	this->_raw_bits = (this->toFloat() / other.toFloat()) * (1 << _fract_bits);
	return (*this);
}

Fixed	Fixed::operator++()
{
	this->_raw_bits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);
	++(*this);
	return (result);
}

Fixed	Fixed::operator--()
{
	this->_raw_bits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);
	--(*this);
	return (result);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
