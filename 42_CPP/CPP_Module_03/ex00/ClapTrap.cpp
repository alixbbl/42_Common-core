/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:46:03 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 13:36:37 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

// constructeur par defaut
ClapTrap::ClapTrap() : _name("default"), _hitPoints(10),
			_energyPoints(10), _attackDamagePoints(0) {
	std::cout << "Default constructor called" << std::endl;
}

// constructeur avec parametre
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
			_energyPoints(10), _attackDamagePoints(0) {
	std::cout << "Constructor -" << name << "- called" << std::endl;
}

// operateur de recopie (on recopie les data de l' objet other dans this)
ClapTrap::ClapTrap(const ClapTrap &other) {

	std::cout << "Copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamagePoints = other._attackDamagePoints;
}

// operateur d' affectation/assignation
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {

	if (this != &other) { // eviter d' affecter un objet a lui-meme
		std::cout << "Assignation operator called" << std::endl;
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamagePoints = other._attackDamagePoints;
	}
	return *this;
}

// destructeur
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/********************************* OFSTREAM ***********************************/

// Définition de la surcharge de l'opérateur de flux
std::ostream &operator<<(std::ostream &stream, ClapTrap &clapTrap) {

	stream << "Name: " << clapTrap.get_Name() << std::endl;
	stream << "Hitpoints: " << clapTrap.get_Hit() << std::endl;
	stream << "EnergyPoints: " << clapTrap.get_Energy() << std::endl;
	stream << "AttackDamage: " << clapTrap.get_AttackDamage() << std::endl;

	return stream;
}

/********************************* GETTERS ***********************************/

std::string ClapTrap::get_Name(void){
	return (this->_name);
}

int	ClapTrap::get_Hit(void) {
	return (this->_hitPoints);
}

int	ClapTrap::get_Energy(void) {
	return (this->_energyPoints);
}

int	ClapTrap::get_AttackDamage(void) {
	return (this->_attackDamagePoints);
}

/********************************* SETTERS ***********************************/

void	ClapTrap::set_hitPoints(int new_hit) {
	this->_hitPoints = new_hit;
}

void	ClapTrap::set_energyPoints(int new_energy) {
	this->_energyPoints = new_energy;
}

void	ClapTrap::set_attackDamagePoints(int new_damage) {
	this->_attackDamagePoints = new_damage;
}

/***************************** OTHER FUNCTIONS *******************************/

void	ClapTrap::attack(const std::string& target) {

	if (this->get_Energy() < 1 || this->get_Hit() < 1){
		std::cout	<< this->get_Name()
					<< " has not enough energy points to attack!"
					<< std::endl;
		return ; }

	set_energyPoints(this->get_Energy() - 1);

	std::cout	<< this->get_Name() << " attacks " << target
				<< ", causing " << this->get_AttackDamage()
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	int new_hit = this->get_Hit() - amount;
	set_hitPoints(new_hit);

	std::cout	<< this->get_Name() << " has lost " << amount
				<< " points of life (Hit)! Total of Hit points is now "
				<< this->get_Hit() << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (_energyPoints < 1) {
	std::cout << "Not enough energy points to repair!" << std::endl;
	return ; }
	set_energyPoints(this->get_Energy() - 1);
	set_hitPoints(this->get_Hit() + amount);

	std::cout	<< this->get_Name() << " has repaired and gained "
				<< amount << " points of hit(life)! Total of Hit points is now "
				<< this->get_Hit() << std::endl;
}
