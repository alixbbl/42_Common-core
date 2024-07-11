/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:37:29 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 15:51:27 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS *************************/

FragTrap::FragTrap() : ClapTrap() {

	this->_Name = ("default");
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamagePoints = 30;
	std::cout << "FRAGTRAP default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->_Name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamagePoints = 30;
	std::cout	<< "Fragtrap constructor for -" << name
				<< "- called" << std::endl;
}


FragTrap::FragTrap(const FragTrap &origin) : ClapTrap(origin) {

	this->_hitPoints = 100; // on met a jour les valeurs.
	this->_energyPoints = 100;
	this->_attackDamagePoints = 30;
	std::cout << "FRAGTRAP copy constructor called." << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &origin) {

	if (this != &origin) {
		std::cout << "FRAGTRAP assignation operator called." << std::endl;
		_Name = origin._Name;
		_hitPoints = origin._hitPoints;
		_energyPoints = origin._energyPoints;
		_attackDamagePoints = origin._attackDamagePoints; }
	return *this;
}

FragTrap::~FragTrap() {

	std::cout	<< "FRAGTRAP " << this->get_Name() << " disappeared!!!"
				<< std::endl;
}
/***************************** OTHER FUNCTIONS *******************************/

// nouvelle fonction avec demande au user, faut-il proteger le input ???
void FragTrap::highFivesGuys(void) {

	std::string input;

	std::cout	<< "Let's chill a bit, do you need a high five (yes/no)?"
				<< std::endl;
	std::cin >> input;
	if (input == "yes") {
		std::cout	<< "(Fragtrap) " << this->get_Name()
					<< " is a nice guy, just wanna.... HIGHFIVE"
					<< std::endl; }
	else
		std::cout	<< "All right you depressing person..." << std::endl;
	return ;
}
