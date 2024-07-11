/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:38:19 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/21 17:08:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS *************************/

ScavTrap::ScavTrap() : ClapTrap() {

	this->_Name = ("default");
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamagePoints = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamagePoints = 20;
	std::cout << "ScavTrap constructor with name : " << name
	<< "was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &origin) : ClapTrap(origin) {

	this->_hitPoints = 100; // on personnalise ici les valeurs.
	this->_energyPoints = 50;
	this->_attackDamagePoints = 20;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// operateur d'affectation
ScavTrap &ScavTrap::operator=(const ScavTrap &origin) {

	if (this != &origin) {
		std::cout << "Assignation operator called" << std::endl;
		_Name = origin._Name;
		_hitPoints = origin._hitPoints;
		_energyPoints = origin._energyPoints;
		_attackDamagePoints = origin._attackDamagePoints; }
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout	<< "ScavTrap" << this->get_Name() << "destroyed"
				<< std::endl;
}

/***************************** OTHER FUNCTIONS *******************************/

void	ScavTrap::attack(std::string& target) {

	if (this->get_Hit() <= 0) {
		std::cout << "ScavTrap is too weak to attack! ('bout to diiiie)" << std::endl;
		return ; }

	if (this->_Name == target) {
		std::cout << "OH NO ! ScavTrap is in self destruction mode !" << std::endl;
		this->_hitPoints = 0;
		return ; }

	if (this->get_Energy() < 1) {
		std::cout << "ScavTrap has no more energy !" << std::endl;
		return ; }

	return ;
}

void	ScavTrap::guardGate(void) {

	if (this->get_Energy() < 1){
		std::cout	<< "ScavTrap hasn't enough energy points to guard the gates!"
					<< std::endl;
		return ;
	}
	// Guardian Mode
	std::cout	<< "ScavTrap called " << this->_Name
				<< " shouts loudly ... YOU SHALL NOT PASS!!! "
				<< std::endl;
	return ;
}
