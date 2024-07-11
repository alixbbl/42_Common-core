/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:43:33 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 15:51:54 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <string>
#include <iostream>

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

HumanA::HumanA(std::string name, Weapon &weapon_A) : _name(name), _weapon(weapon_A)
{
	std::cout << "Human A constructor called" << std::endl;
	return ;
}

HumanA::~HumanA() {

	std::cout << "Human A destructor called" << std::endl;
	return ;
}

/***************************** OTHER FUNCTION ********************************/

void	HumanA::attack(void) {

	std::cout	<< this->_name << " attacks with their "
				<< this->_weapon.getType()
				<< std::endl ;
}
