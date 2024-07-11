/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:04:16 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/15 09:19:21 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

Zombie::Zombie() {

    std::cout << "New zombie :" << this->_name << " was created." << std::endl;
}

Zombie::~Zombie() {

    std::cout   << "New zombie : " << this->_name
                << " was destroyed." << std::endl;
}


/******************************* OTHER FUNCTIONS ******************************/

Zombie *newZombie(std::string name) {

    Zombie *zombie = new Zombie();
    zombie->set_Name(name);
    zombie->announce();
    return zombie; }
