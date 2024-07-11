/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 15:48:53 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

/*
Il est ok de definir les constructeurs et destructeurs dans le hpp si le code
est court, sinon on les mets dans un .cpp separe comme ici.
*/

/************************* COSNTRUCTOR & DESTRUCTOR ***************************/

Weapon::Weapon() {

    _type = "default";
    std::cout << "Weapon default constructor called" << std::endl;
    return ;
}

Weapon::Weapon(std::string weapon_name) {

    std::cout << "Weapon constructor with name called" << std::endl;
    _type = weapon_name;
    return ;
}

Weapon::~Weapon() {

    std::cout << "Weapon destructor called" << std::endl;
    return ;
}


/***************************** SETTERS & GETTERS ******************************/

std::string const   &Weapon::getType() {
    return (_type);
}

void	Weapon::setType(std::string type_of_weapon) {
    this->_type = type_of_weapon;
    return ;
}
