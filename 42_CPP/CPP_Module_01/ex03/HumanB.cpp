/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:43:15 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 10:51:51 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

// signifie que le champs membre _name est initialise avec la valeur name"
// passee en parametre lors de l'appel a la fonction.
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	return ;
}

HumanB::~HumanB() {
	return ;
}

/***************************** OTHER FUNCTIONS *******************************/

void	HumanB::attack(void) {

	if (this->_weapon) {

		std::cout	<< this->_name << " attacks with their "
					<< this->_weapon->getType()
					<< std::endl; }
	else
		std::cout	<< this->_name << " attacks with fists!"
					<< std::endl;

}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
